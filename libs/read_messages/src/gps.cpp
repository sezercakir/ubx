/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : gps.c file
 * @details :
 */

#include "gps.hpp"
#include "gnss_base.hpp"
#include "exception.hpp"

void Gps::read_sfrbx (const settings_t& json)
{
    std::ifstream fileStream(json.fpath+json.fname, std::ios::in | std::ios::binary);
    if (!fileStream.is_open()) throw Exception{"File Cannot Opened"};

    SFRBX_frame_gps ubx_gps{};
    GPS_TLM_t   w1{};
    GPS_HOW_t   w2{};

    while (fileStream.tellg() != -1){
        read_from_file(fileStream, ubx_gps.preamble1);
        read_from_file(fileStream, ubx_gps.preamble2);
        read_from_file(fileStream, ubx_gps.messageClass);
        read_from_file(fileStream, ubx_gps.messageID);
        read_from_file(fileStream, ubx_gps.length);


        // UBX-RXM-SFRBX message check
        if (json.prebei == ubx_gps.preamble1 && json.prebei2 == ubx_gps.preamble2 &&
            json.msgcls == ubx_gps.messageClass && json.msgid == ubx_gps.messageID &&
            json.pyl_lgth_gps == ubx_gps.length){

            read_from_file(fileStream, ubx_gps.payload);
            read_from_file(fileStream, ubx_gps.checksumA);
            read_from_file(fileStream, ubx_gps.checksumB);


            if (json.gnss_id_gps ==  ubx_gps.payload.gnssId && (json.sv_bgn <= ubx_gps.payload.svId  &&
                    ubx_gps.payload.svId <= json.sv_gps_num)){


                w1.word         = ubx_gps.payload.word[0];
                w2.word         = ubx_gps.payload.word[1];
                int pageId      = static_cast<int>(GPS_Word3_t{ubx_gps.payload.word[2]}.pageid);
                int subframe    = static_cast<int>(w2.subID);


                if (calc_checksum(ubx_gps)){

                    switch (subframe)
                    {
                        case 1:
                            m_gpframes[std::make_pair("Subframe_1","Page_none")].push_back(ubx_gps);m_message_size++;
                        case 2:
                            m_gpframes[std::make_pair("Subframe_2","Page_none")].push_back(ubx_gps);m_message_size++;
                        case 3:
                            m_gpframes[std::make_pair("Subframe_3","Page_none")].push_back(ubx_gps);m_message_size++;
                        case 4:
                            m_gpframes[std::make_pair("Subframe_4","Page_"+std::to_string(pageId))].push_back(ubx_gps);m_message_size++;
                        case 5:
                            m_gpframes[std::make_pair("Subframe_5","Page_"+std::to_string(pageId))].push_back(ubx_gps);m_message_size++;
                        default: std::cout << "GPS Subframe Cannot Find" << subframe << "\n";
                    }


                    switch(ubx_gps.payload.reserved0){
                        case 0: /* GPS L1|CA */
                            break;
                        case 3: /* GPS L2|CL */
                            break;
                        case 4: /* GPS L2|CM */
                            break;
                        case 6: /* GPS L5|1 */
                            break;
                        case 7: /* GPS L5|Q */
                            break;
                        default:     /* error */    break;
                    }
                }
            }
        }
        else{
            // set the current position to end of the subframe
            // here d.length is for payload length and plus 2 is for 2 byte checksum (checksum A + checksum B)
            fileStream.seekg((ubx_gps.length + 2), std::ios::cur);
        }
    }
    fileStream.close();
    //std::cout << m_message_size << "\n";
    //std::cout << m_gpframes[std::make_pair("Subframe_3","Page_none")].size() << "\n";
    //std::cout << m_gpframes[std::make_pair("Subframe_2","Page_none")].size() << "\n";
    //std::cout << m_gpframes[std::make_pair("Subframe_1","Page_none")].size() << "\n";
    //std::cout << m_gpframes[std::make_pair("Subframe_4","Page_4")].size() << "\n";
    //std::cout << m_gpframes[std::make_pair("Subframe_5","Page_5")].size() << "\n";
}

