cmake_minimum_required(VERSION 3.17.3)
project(utils)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES "src/*.cpp" "includes/*.hpp")

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.78.0_1/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.78.0_1/lib)
find_package(Boost 1.78.0)
include_directories(${Boost_INCLUDE_DIR})

if (Boost_FOUND)
    message(STATUS "Boost Finded")
endif ()

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:includes>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
        ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/libs/read_messages/inc
        ${CMAKE_SOURCE_DIR}/libs/utils/inc
        )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
