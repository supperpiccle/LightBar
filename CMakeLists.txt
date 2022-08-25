# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("LightBar")

set(test_bin "C:/Users/cplus/source/repos/LightBar/build/bin/Debug")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

set(CURL_USE_OPENSSL, ON)


# Include sub-projects.
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#include_directories(third-party/googletest/googletest/include)

add_subdirectory(third-party)

add_subdirectory (LightBar)
add_subdirectory (StockUtil)
add_subdirectory (test)