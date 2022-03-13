/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : gps.c file
 * @details : 
 */

#include "gps.hpp"

void Gps::read_gnss (const settings_t& json)
{
    std::ifstream fileStream(json.fpath+json.fname, std::ios::in | std::ios::binary);
    if (!fileStream.is_open()) throw Exception{"File Cannot Opened"};

    UBXframe ubx{};
    
    while (fileStream.tellg() != -1){
        read_from_file(fileStream, ubx.preamble1);
        read_from_file(fileStream, ubx.preamble2);
        read_from_file(fileStream, ubx.messageClass);
        read_from_file(fileStream, ubx.messageID);
        read_from_file(fileStream, ubx.length);


        // UBX-RXM-SFRBX message check
        if (json.prebei == (ubx.preamble1) && json.prebei2 == ubx.preamble2 &&
            json.msgcls == (ubx.messageClass) && json.msgid == ubx.messageID &&
            json.pyl_lgth == ubx.length){

            read_from_file(fileStream, ubx.payload);
            read_from_file(fileStream, ubx.checksumA);
            read_from_file(fileStream, ubx.checksumB);


            if (json.gnss_id ==  ubx.payload.gnssId && (json.sv_bgn <= ubx.payload.svId  &&
                                                        ubx.payload.svId <= json.sv_bei_num)){
                /*
                 * calculate checksum if return true from calc_checksum than decode the
                 * requested subframe and page
                 */

                GPS_TLM_t w1;
                GPS_HOW_t w2;

                w1.word = ubx.payload.word[0];
                w2.word = ubx.payload.word[1];

                /*
                 * It can be controlled output via subframeid or pageid variable given from settings.json
                 * in the if block below
                 */
                if (calc_checksum(ubx)){

                    m_message_size++;

                    switch(ubx.payload.reserved0){
                        case 0: /* GPS L1|CA */
                            frames[0].push_back(ubx);
                            break;
                        case 3: /* GPS L2|CL */
                            frames[3].push_back(ubx);
                            break;
                        case 4: /* GPS L2|CM */
                            frames[4].push_back(ubx);
                            break;
                        case 6: /* GPS L5|1 */
                            frames[6].push_back(ubx);
                            break;
                        case 7: /* GPS L5|Q */
                            frames[7].push_back(ubx);
                            break;
                        default:     /* error */    break;
                    }
                }
            }
        }
        else{
            // set the current position to end of the subframe
            // here d.length is for payload length and plus 2 is for 2 byte checksum (checksum A + checksum B)
            fileStream.seekg((ubx.length + 2), std::ios::cur);
        }
    }
    fileStream.close();

}



