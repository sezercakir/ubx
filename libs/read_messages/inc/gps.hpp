/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 19 / March / 2022
 * @code    : gps.h file
 * @details : 
 */



#ifndef GPS_HPP
#define GPS_HPP

#include "gnss_base.hpp"


typedef struct{
    uint8_t gnssId;
    uint8_t svId;
    uint8_t reserved0;
    uint8_t freqId;
    uint8_t numWords;
    uint8_t chn;
    uint8_t version;
    uint8_t reserved1;
    uint32_t word[10];
} Payload_gps;

typedef struct{
    uint8_t preamble1;
    uint8_t preamble2;
    uint8_t messageClass;
    uint8_t messageID;
    uint16_t length;
    Payload_gps payload;
    uint8_t checksumA;
    uint8_t checksumB;
} SFRBX_frame_gps;                                     //!< GPS UBlox SFRBX Message Packet


/************ GPS Words **********/

typedef union
{
    struct
    {
        uint32_t parity     : 6;
        uint32_t reserved   : 16;
        uint32_t preamble   : 8;
        uint32_t padding    : 2;
    };
    uint32_t word;
} GPS_TLM_t ;

typedef union
{
    struct
    {
        uint32_t parity       : 6;
        uint32_t preserve_    : 1;
        uint32_t preserve     : 1;
        uint32_t subID        : 3;
        uint32_t anti_spoof   : 1;
        uint32_t alet_flag    : 1;
        uint32_t TOW          : 17;
        uint32_t padding      : 2;
    };
    uint32_t word;
} GPS_HOW_t ;

typedef union
{
    struct
    {
        uint32_t x            : 22;
        uint32_t pageid       : 6;
        uint32_t data_id      : 2;
        uint32_t padding      : 2;
    };
    uint32_t word;
} GPS_Word3_t;

class Gps : public Gnss_Base{
public:
    void read_sfrbx(const settings_t&) override;

    std::map<std::pair<std::string, std::string>, std::vector<SFRBX_frame_gps> > m_gpframes{};      //!< keys = subframeId, pageId; value = payload words
};






#endif /* GPS_HPP */