cmake_minimum_required(VERSION 3.17.3)
project(Gnss_Msg)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(App)
add_subdirectory(Libs)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion -Wnon-c-typedef-for-linkage)