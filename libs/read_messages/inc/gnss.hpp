/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 19 / March / 2022
 * @code    : gnss.h file
 * @details : 
 */



#ifndef GNSS_HPP
#define GNSS_HPP
#include "gps.hpp"
#include "beidou.hpp"
#include "glonass.hpp"
#include "galileo.hpp"
#include "data_types.hpp"

class  Gnss{
    Gps m_gps{};
    Beidou m_beidou{};
    Galileo m_galileo{};
    Glonass m_glonass{};
public:
    Gnss() = default;
    void run_sfrbx(const settings_t&);
};

#endif /* GNSS_HPP */