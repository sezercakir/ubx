/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : beidou.h file
 * @details : 
 */



#ifndef BEIDOU_HPP
#define BEIDOU_HPP
#include "gnss_base.hpp"

class Beidou : public  Constellations{
    void read_gnss(const settings_t&) override;
};


#endif /* BEIDOU_HPP */