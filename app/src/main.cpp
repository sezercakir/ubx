/**
 * @file    : read_gnssMsg project file
 * @author  : Sezer Çakır, Mehmet Kaan Erol
 * @date    : 10 / March / 2022
 * @code    : main.cpp file
 * @details : 
 */

#include <iostream>
#include <vector>
#include "data_types.hpp"
#include "utils_lib.hpp"
#include "gnss.hpp"
#include "exception.hpp"
#include "gnss_base.hpp"

int main()
{
    /// main data structure
    settings_t json_data{};
    std::vector<UBXframe> ubxframes{};
    try
    {
        readjson(json_data);

        switch (json_data.gnss_id)
        {
            case GNSS_ID::GPS:
                Gps* gps = new Gps();
            case GNSS_ID::GALILEO :
                //read_gelileo();
            case GNSS_ID::BEIDOU :
                read_beidou(json_data, ubxframes);
            case GNSS_ID::GLONASS :
                //read_glonass();
            default:
                break;
        }
        std::cout << ubxframes.size();
        // write_frames(ubxframes);
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

