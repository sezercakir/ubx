/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 19 / March / 2022
 * @code    : gnss.c file
 * @details : 
 */


#include "gnss.hpp"
#include "gps.hpp"


void Gnss::run_sfrbx(const settings_t& settings_in)
{
    m_gps.read_sfrbx(settings_in);
    m_beidou.read_sfrbx(settings_in);
    //m_galileo.read_sfrbx(settings_in);
    //m_glonass.read_sfrbx(settings_in);
}
