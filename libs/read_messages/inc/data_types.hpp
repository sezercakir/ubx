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

#define JSON_PATH "/Users/sezer/Desktop/github/ubx/settings.json"

/****** JSON Data ***********/
typedef struct
{
    std::string fname{};
    std::string fpath{};
    uint32_t gnss_id_gps{};
    uint32_t gnss_id_bei{};
    uint32_t gnss_id_glo{};
    uint32_t gnss_id_gal{};
    uint32_t sigid{};
    uint32_t svid{};
    uint32_t subframeid{};
    uint32_t pageid{};
    uint32_t prebei{};
    uint32_t prebei2{};
    uint32_t msgcls{};
    uint32_t msgid{};
    uint32_t num_wrd_gps{};
    uint32_t num_wrd_bei{};
    uint32_t num_wrd_glo{};
    uint32_t num_wrd_gal{};
    uint32_t pyl_lgth_gps{};
    uint32_t pyl_lgth_bei{};
    uint32_t pyl_lgth_glo{};
    uint32_t pyl_lgth_gal{};
    uint32_t sv_bgn{};
    uint32_t sv_gps_num{};
    uint32_t sv_bei_num{};
    uint32_t sv_glo_num{};
    uint32_t sv_gal_num{};
}settings_t;

enum  class Constellation
{
    Gps,
    Galileo,
    Beidou,
    Glonass
};

enum GPS_Subframes : int
{
    Subframe1   = 1,
    Subframe2   = 2,
    Subframe3   = 3,
    Subframe4   = 4,
    Subframe5   = 5
};

enum GNSS_ID : std::int8_t
{
    GPS         = 0,
    GALILEO     = 2,
    BEIDOU      = 3,
    GLONASS     = 6
};



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
