/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : galileo.c file
 * @details : 
 */


#include "galileo.hpp"

void Galileo::read_gnss (const settings_t &json)
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

            // Payload checker kontrol fonksiyonu koyulablir
            if (json.gnss_id ==  ubx.payload.gnssId && (json.sv_bgn <= ubx.payload.svId  &&
                                                        ubx.payload.svId <= json.sv_bei_num)){
                /*
                 * calculate checksum if return true from calc_checksum than decode the
                 * requested subframe and page
                 */

                //Galileo_Word_t_1 w1;
                //Galileo_Word_t_2 w2;

                //w1.word = ubx.payload.word[0];
                //w2.word = ubx.payload.word[1];

                if (calc_checksum(ubx)){

                    m_message_size++;

                    switch(ubx.payload.reserved0){
                        case 0: /* Galielo E1|C */
                            frames[0].push_back(ubx);
                            break;
                        case 1: /* Galielo E1|B */
                            frames[1].push_back(ubx);
                            break;
                        case 3: /* Galielo E5|AL */
                            frames[3].push_back(ubx);
                            break;
                        case 4: /* Galielo E5|AQ */
                            frames[4].push_back(ubx);
                            break;
                        case 5: /* Galielo E5|BL */
                            frames[5].push_back(ubx);
                            break;
                        case 6: /* Galielo E5|BQ */
                            frames[6].push_back(ubx);
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

