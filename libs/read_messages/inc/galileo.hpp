/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 13 / March / 2022
 * @code    : galileo.h file
 * @details : 
 */



#ifndef GALILEO_HPP
#define GALILEO_HPP

#include "gnss_base.hpp"

class Galileo : public Constellations{
    void read_gnss(const settings_t&) override;
};


#endif /* GALILEO_HPP */