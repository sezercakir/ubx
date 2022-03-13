cmake_minimum_required(VERSION 3.15)
project(App)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES "src/*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES} )
target_link_libraries(${PROJECT_NAME} PRIVATE
        libs::read_messages
        libs::utils
        )



