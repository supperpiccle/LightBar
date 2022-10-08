cmake_minimum_required (VERSION 3.8)

add_executable(LightBarTests LightBarTests.cpp)
target_link_libraries(LightBarTests PUBLIC gtest_main gtest gmock)
target_link_libraries(LightBarTests PUBLIC rapidjson)
target_link_libraries(LightBarTests PUBLIC LightBar_main)
target_link_libraries(LightBarTests PUBLIC StockUtils_lib)

set_target_properties (
    LightBarTests PROPERTIES
    CXX_STANDARD 17
    )