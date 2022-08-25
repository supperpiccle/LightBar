cmake_minimum_required (VERSION 3.8)

add_subdirectory (googletest)
add_subdirectory (curl)
add_subdirectory (rapidjson)

add_library(rapidjson INTERFACE)
target_include_directories(rapidjson INTERFACE rapidjson/include)