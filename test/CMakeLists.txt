cmake_minimum_required (VERSION 3.8)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

set (SOURCES StockTests.cpp)
add_executable(StockTests StockTests.cpp)
add_executable(LedMatrixTests LedMatrixTest.cpp)
target_include_directories(LedMatrixTests PRIVATE ../third-party/rapidjson/include)

set_target_properties (
    LedMatrixTests PROPERTIES
    CXX_STANDARD 17
    )

target_link_libraries(StockTests PUBLIC gtest_main gtest)
target_link_libraries(StockTests PUBLIC yahoo-finance)
target_include_directories(StockTests PUBLIC ../third-party/yahoo-finance/src)

target_link_libraries(LedMatrixTests PUBLIC LightBar_lib)

INSTALL(TARGETS StockTests DESTINATION ${HelloCMake_SOURCE_DIR}/assets)

