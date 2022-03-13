/**
 * @file    : Gnss_Msg project file
 * @author  : Sezer Çakır
 * @date    : 10 / March / 2022
 * @code    : exception.h file
 * @details : 
 */



#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>

class Exception: public std::exception
{
    std::string what_message;
public:
    explicit Exception(std::string  msg) : what_message(std::move(msg)){}
    Exception()= default;
    const char* what() const noexcept override{
        return what_message.c_str();
    }
};

#endif /* EXCEPTION_HPP */