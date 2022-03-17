/**
 * @file    : read_gnssMsg project file
 * @author  : Sezer Çakır, Mehmet Kaan Erol
 * @date    : 10 / March / 2022
 * @code    : data_types.hpp file
 * @details : 
 */



#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

#include <fstream>
#include <iostream>

#define JSON_PATH "/Users/sezer/CLionProjects/algo1/read_gnssMsg/settings.json"

/****** JSON Data ***********/
typedef struct
{
    std::string fname{};
    std::string fpath{};
    uint32_t gnss_id{};
    uint32_t sigid{};
    uint32_t svid{};
    uint32_t subframeid{};
    uint32_t pageid{};
    uint32_t pregps      = 0x8B;
    uint32_t prebei{};
    uint32_t prebei2{};
    uint32_t msgcls      = 2;
    uint32_t msgid       = 19;
    uint32_t num_wrd     = 10;
    uint32_t pyl_lgth    = 8 + num_wrd*4;
    uint32_t sv_bgn      = 1;
    uint32_t sv_gps_num  = 32;
    uint32_t sv_bei_num  = 63;
}settings_t;

enum  class Constellation
{
    Gps,
    Galileo,
    Beidou,
    Glonass
};


enum GNSS_ID : std::int8_t
{
    GPS         = 0,
    GALILEO     = 2,
    BEIDOU      = 3,
    GLONASS     = 6
};

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

/************ Beidou Words **********/

typedef union
{
    struct
    {
        uint32_t parity : 4;
        uint32_t sow    : 8;
        uint32_t subid  : 3;
        uint32_t x      : 4;
        uint32_t xx     : 11;
        uint32_t pad    : 2;
    };
    uint32_t word;
} BeiDou_Word_1_t;

typedef union
{
    struct
    {
        uint32_t parity : 8;
        uint32_t x      : 2;
        uint32_t pnum   : 7;
        uint32_t xx     : 1;
        uint32_t xxx    : 12;
        uint32_t xxxx   : 2;
    };
    uint32_t word;
} BeiDou_Word_2_t;

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
} Payload;


typedef struct{
    uint8_t preamble1;
    uint8_t preamble2;
    uint8_t messageClass;
    uint8_t messageID;
    uint16_t length;
    Payload payload;
    uint8_t checksumA;
    uint8_t checksumB;
} UBXframe;



#endif /* DATA_TYPES_HPP */
