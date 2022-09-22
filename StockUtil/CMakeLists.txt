cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (StockUtils_lib STATIC Stock.cpp Stock.h)
target_link_libraries(StockUtils_lib PUBLIC libcurl)
target_link_libraries(StockUtils_lib PUBLIC rapidjson)
target_link_libraries(StockUtils_lib PUBLIC LightBarInterface_lib)
target_link_libraries(StockUtils_lib PUBLIC LightBar_lib)

target_include_directories(StockUtils_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set_target_properties (
    StockUtils_lib PROPERTIES
    CXX_STANDARD 17
    )

 add_custom_target(copy-stock-script ALL
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/stock_data_getter.py
    ${CMAKE_BINARY_DIR}/bin/stock_data_getter.py
    )