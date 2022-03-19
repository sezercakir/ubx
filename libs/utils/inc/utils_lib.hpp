/**
 * @file    : read_gnssMsg project file
 * @author  : Sezer Çakır, Mehmet Kaan Erol
 * @date    : 10 / March / 2022
 * @code    : utils_lib.h file
 * @details : 
 */



#ifndef UTILS_LIB_HPP
#define UTILS_LIB_HPP

#include <iostream>
#include "data_types.hpp"
/// Prototypes
void readjson(settings_t& json);

template <class T>
void read_from_file(std::ifstream& fileStream, T& variable){
    fileStream.read((char*) &variable, sizeof(variable));
}

template<typename T>
bool calc_checksum(T d){
    uint8_t *data = (&d.messageClass);
    std::cout <<*data;
    uint8_t CK_A = 0, CK_B = 0;
    for(int i=0;i<sizeof(d) - 6;i++)
    {
        if (i == 4 || i == 5) continue;
        //std::cout << std::hex << (uint) data[i] <<  " ";
        CK_A = CK_A + data[i];
        CK_B = CK_A + CK_B;
    }

    if (CK_A == d.checksumA && CK_B == d.checksumB){
        return 1;
    }
    return 0;
}

#endif /* UTILS_LIB_HPP */
