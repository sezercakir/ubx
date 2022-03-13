/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : glonass.h file
 * @details : 
 */



#ifndef GLONASS_HPP
#define GLONASS_HPP

#include "gnss_base.hpp"

class Glonass : public Constellations{
    void read_gnss(const settings_t&) override;
};

#endif /* GLONASS_HPP */