/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : constellations.h file
 * @details : 
 */



#ifndef GNSS_BASE_HPP
#define GNSS_BASE_HPP


#include "data_types.hpp"
#include "exception.hpp"
#include "utils_lib.hpp"
#include <iostream>
#include <map>
#include <vector>

class Gnss_Base{
private:

public:
    Gnss_Base() = default;

    virtual void read_sfrbx(const settings_t&) = 0;

    int m_message_size{};
};

#endif /* GNSS_BASE_HPP */