cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (StockUtils_lib STATIC Stock.cpp Stock.h)
target_link_libraries(StockUtils_lib PUBLIC libcurl)
target_link_libraries(StockUtils_lib PUBLIC rapidjson)
target_include_directories(StockUtils_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})