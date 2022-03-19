/**
 * @file    : read_gnssMsg project file
 * @author  : Sezer Çakır, Mehmet Kaan Erol
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
    json_data.prebei2       = pt.get<uint32_t>("PRE2_BEI");
    json_data.gnss_id_gps   = pt.get<uint32_t>("GNSS_ID_GPS");
    json_data.gnss_id_bei   = pt.get<uint32_t>("GNSS_ID_BEI");
    json_data.gnss_id_glo   = pt.get<uint32_t>("GNSS_ID_GLO");
    json_data.gnss_id_gal   = pt.get<uint32_t>("GNSS_ID_GAL");
    json_data.sigid         = pt.get<uint32_t>("SIG_ID");
    json_data.svid          = pt.get<uint32_t>("SV_ID");
    json_data.subframeid    = pt.get<uint32_t>("SUBFRAME_ID");
    json_data.pageid        = pt.get<uint32_t>("PAGE_ID");
    json_data.msgcls        = pt.get<uint32_t>("MSG_CLS");
    json_data.msgid         = pt.get<uint32_t>("MSG_ID");
    json_data.num_wrd_gps   = pt.get<uint32_t>("NUM_WRD_GPS");
    json_data.num_wrd_bei   = pt.get<uint32_t>("NUM_WRD_BEI");
    json_data.num_wrd_glo   = pt.get<uint32_t>("NUM_WRD_GLO");
    json_data.pyl_lgth_gps  = 8 + json_data.num_wrd_gps * 4;
    json_data.pyl_lgth_bei  = 8 + json_data.num_wrd_bei * 4;
    json_data.pyl_lgth_glo  = 8 + json_data.num_wrd_glo * 4;
    json_data.pyl_lgth_gal  = 8 + json_data.num_wrd_gal * 4;
    json_data.sv_bgn        = pt.get<uint32_t>("SV_BGN");
    json_data.sv_gps_num    = pt.get<uint32_t>("SV_GPS_NUM");
    json_data.sv_bei_num    = pt.get<uint32_t>("SV_BEI_NUM");
}



