/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır, Mehmet Kaan Erol
 * @date    : 13 / March / 2022
 * @code    : beidou.c file
 * @details : 
 */


#include "beidou.hpp"
#include "gnss_base.hpp"

/**
 * @brief Paketler subframe ve page bilgisine göre
 * dictionary yapısı olan std::map'te toplanır. Doğru şekilde
 * toplandıktan sonra dosyaya TODO yazılacak.
 * @param json
 */

void Beidou::read_sfrbx (const settings_t &json)
{
    std::ifstream fileStream(json.fpath+json.fname, std::ios::in | std::ios::binary);

    if (!fileStream.is_open()) throw Exception{"File Cannot Opened"};

    UBXframe_bei_t bei_sfrbx{};
    BeiDou_Word_1_t w1{};
    BeiDou_Word_2_t w2{};

    while (fileStream.tellg() != -1){
        read_from_file(fileStream, bei_sfrbx.preamble1);
        read_from_file(fileStream, bei_sfrbx.preamble2);
        read_from_file(fileStream, bei_sfrbx.messageClass);
        read_from_file(fileStream, bei_sfrbx.messageID);
        read_from_file(fileStream, bei_sfrbx.length);


        // UBX-RXM-SFRBX message check
        if (json.prebei == (bei_sfrbx.preamble1) && json.prebei2 == bei_sfrbx.preamble2 &&
            json.msgcls == (bei_sfrbx.messageClass) && json.msgid == bei_sfrbx.messageID &&
            json.pyl_lgth_bei == bei_sfrbx.length){

            read_from_file(fileStream, bei_sfrbx.payload);
            read_from_file(fileStream, bei_sfrbx.checksumA);
            read_from_file(fileStream, bei_sfrbx.checksumB);

            if (json.gnss_id_bei ==  bei_sfrbx.payload.gnssId && (json.sv_bgn <= bei_sfrbx.payload.svId  &&
                    bei_sfrbx.payload.svId <= json.sv_bei_num)){



                w1.word = bei_sfrbx.payload.word[0];
                w2.word = bei_sfrbx.payload.word[1];



                if (calc_checksum(bei_sfrbx)){

                    switch (static_cast<int>(w1.subid))
                    {
                        case 1:
                            m_beiframes[std::make_pair("Subframe_1","Page_none")].push_back(bei_sfrbx);m_message_size++;
                        case 2:
                            m_beiframes[std::make_pair("Subframe_2","Page_none")].push_back(bei_sfrbx);m_message_size++;
                        case 3:
                            m_beiframes[std::make_pair("Subframe_3","Page_none")].push_back(bei_sfrbx);m_message_size++;
                        case 4:
                            m_beiframes[std::make_pair("Subframe_4","Page_"+std::to_string(static_cast<int>(w2.pnum)))].push_back(bei_sfrbx);m_message_size++;
                        case 5:
                            m_beiframes[std::make_pair("Subframe_5","Page_"+std::to_string(static_cast<int>(w2.pnum)))].push_back(bei_sfrbx);m_message_size++;
                        // default: NONE
                    }

                    switch(bei_sfrbx.payload.reserved0){
                        case 0: /* BeiDou B1I|D1 */
                            break;
                        case 1: /* BeiDou B1I|D2 */
                            break;
                        case 2: /* BeiDou B2I|D1 */
                            break;
                        case 3: /* BeiDou B2I|D2 */
                            break;
                        default: throw Exception{"Invalid SigID For Beidou" };
                    }
                }
            }
        }
        else{
            // set the current position to end of the subframe
            // here d.length is for payload length and plus 2 is for 2 byte checksum (checksum A + checksum B)
            fileStream.seekg((bei_sfrbx.length + 2), std::ios::cur);
        }
    }
    fileStream.close();
    std::cout << "Beidodu Message Size " << m_message_size << "\n";

}
