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
#include "exception.hpp"
#include "gnss_base.hpp"
#include "gps.hpp"
#include "gnss.hpp"

int main()
{
    /// main data structure
    settings_t json_data{};
    Gnss gnss{};
    try
    {
        readjson(json_data);

        gnss.run_sfrbx(json_data);

    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

