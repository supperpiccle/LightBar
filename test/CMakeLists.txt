cmake_minimum_required (VERSION 3.8)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

set (SOURCES StockTests.cpp)

add_executable(LedMatrixTests LedMatrixTest.cpp)
target_include_directories(LedMatrixTests PRIVATE ../third-party/rapidjson/include)

set_target_properties (
    LedMatrixTests PROPERTIES
    CXX_STANDARD 17
    )

add_executable(StockTests StockTests.cpp)
target_link_libraries(StockTests PUBLIC gtest_main gtest)
target_link_libraries(StockTests PUBLIC StockUtils_lib)
target_link_libraries(StockTests PUBLIC rapidjson)
target_link_libraries(LedMatrixTests PUBLIC LightBar_lib)

set_target_properties (
    StockTests PROPERTIES
    CXX_STANDARD 17
    )

add_subdirectory(LightBarTests)
