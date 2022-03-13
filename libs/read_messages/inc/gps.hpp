/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : gps.h file
 * @details : 
 */



#ifndef GPS_HPP
#define GPS_HPP

#include "gnss_base.hpp"

class Gps : public Constellations{
    void read_gnss(const settings_t&) override;
};

#endif /* GPS_HPP */