/**
 * @file    : read_gnssMsg project file
 * @author  : Sezer Çakır
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

bool calc_checksum(UBXframe d);

#endif /* UTILS_LIB_HPP */