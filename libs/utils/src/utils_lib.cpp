/**
 * @file    : read_gnssMsg project file
 * @author  : Sezer Çakır
 * @date    : 10 / March / 2022
 * @code    : utils_lib.c file
 * @details : 
 */


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "utils_lib.hpp"
#include "data_types.hpp"

void readjson(settings_t& json_data)
{
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(JSON_PATH, pt);

    json_data.fpath         = pt.get<std::string>("FILE_PATH");
    json_data.fname         = pt.get<std::string>("FILE_NAME");
    json_data.prebei        = pt.get<uint32_t>("PRE1_BEI");
    json_data.prebei2        = pt.get<uint32_t>("PRE2_BEI");
    json_data.gnss_id       = pt.get<uint32_t>("GNSS_ID");
    json_data.sigid         = pt.get<uint32_t>("SIG_ID");
    json_data.svid          = pt.get<uint32_t>("SV_ID");
    json_data.subframeid    = pt.get<uint32_t>("SUBFRAME_ID");
    json_data.pageid        = pt.get<uint32_t>("PAGE_ID");
    json_data.msgcls        = pt.get<uint32_t>("MSG_CLS");
    json_data.msgid         = pt.get<uint32_t>("MSG_ID");
    json_data.num_wrd       = pt.get<uint32_t>("NUM_WRD");
    json_data.pyl_lgth      = pt.get<uint32_t>("PYL_LGTH");
    json_data.sv_bgn        = pt.get<uint32_t>("SV_BGN");
    json_data.sv_gps_num    = pt.get<uint32_t>("SV_GPS_NUM");
    json_data.sv_bei_num    = pt.get<uint32_t>("SV_BEI_NUM");
}


bool calc_checksum(UBXframe d){
    uint8_t *data = &d.messageClass;
    std::cout <<*data;
    uint8_t CK_A = 0, CK_B = 0;
    for(int i=0;i<sizeof(d) - 6;i++)
    {
        if (i == 4 || i == 5) continue;
        //std::cout << std::hex << (uint) data[i] <<  " ";
        CK_A = CK_A + data[i];
        CK_B = CK_A + CK_B;
    }

    if (CK_A == d.checksumA && CK_B == d.checksumB){
        return 1;
    }
    return 0;
}

