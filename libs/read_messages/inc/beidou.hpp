/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır, Mehmet Kaan Erol
 * @date    : 13 / March / 2022
 * @code    : beidou.h file
 * @details : 
 */



#ifndef BEIDOU_HPP
#define BEIDOU_HPP

#include "gnss_base.hpp"

class Beidou : public Gnss_Base{
public:
    void read_sfrbx(const settings_t&) override;
    std::map<std::pair<std::string, std::string>, std::vector<UBXframe_bei_t> > m_beiframes{};      //!< keys = subframeId, pageId; value = payload words

};


#endif /* BEIDOU_HPP */
