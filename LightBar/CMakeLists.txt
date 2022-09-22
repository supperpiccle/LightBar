# CMakeList.txt : CMake project for LightBar, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (LightBar_lib STATIC "LightBar.cpp" "LightBar.h" "LedMatrix.h" "LedMatrix.cpp")
target_include_directories(LightBar_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(LightBar_lib INTERFACE /usr/include/GraphicsMagick)
target_include_directories(LightBar_lib PRIVATE /usr/include/GraphicsMagick)

target_link_libraries(LightBar_lib PRIVATE "-lGraphicsMagick++")
target_link_libraries(LightBar_lib PRIVATE "-lGraphicsMagick")
target_link_libraries(LightBar_lib PRIVATE "-ljbig")
target_link_libraries(LightBar_lib PRIVATE "-lwebp")
target_link_libraries(LightBar_lib PRIVATE "-lwebpmux")
target_link_libraries(LightBar_lib PRIVATE "-llcms2")
target_link_libraries(LightBar_lib PRIVATE "-ltiff")
target_link_libraries(LightBar_lib PRIVATE "-lfreetype")
target_link_libraries(LightBar_lib PRIVATE "-ljpeg")
target_link_libraries(LightBar_lib PRIVATE "-lpng16")
target_link_libraries(LightBar_lib PRIVATE "-lwmflite")
target_link_libraries(LightBar_lib PRIVATE "-lXext")
target_link_libraries(LightBar_lib PRIVATE "-lSM")
target_link_libraries(LightBar_lib PRIVATE "-lICE")
target_link_libraries(LightBar_lib PRIVATE "-lX11")
target_link_libraries(LightBar_lib PRIVATE "-llzma")
target_link_libraries(LightBar_lib PRIVATE "-lbz2")
target_link_libraries(LightBar_lib PRIVATE "-lxml2")
target_link_libraries(LightBar_lib PRIVATE "-lz")
target_link_libraries(LightBar_lib PRIVATE "-lzstd")
target_link_libraries(LightBar_lib PRIVATE "-lm")
target_link_libraries(LightBar_lib PRIVATE "-lpthread")
target_link_libraries(LightBar_lib PRIVATE "-lgomp")

add_library(LightBarInterface_lib INTERFACE)
target_include_directories(LightBarInterface_lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})


add_library(LightBar_main STATIC "Animation.h" "Animation.cpp" "Session.h" "Session.cpp" "SessionManager.h" "SessionManager.cpp")
target_include_directories(LightBar_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LightBar_main INTERFACE LightBarInterface_lib)
target_link_libraries(LightBar_main PRIVATE StockUtils_lib)
target_link_libraries(LightBar_main PRIVATE StockUtils_lib)

add_executable(LightBar_exe "main.cpp")
target_link_libraries(LightBar_exe PRIVATE LightBar_main)
target_link_libraries(LightBar_exe PRIVATE LightBar_lib)
target_link_libraries(LightBar_exe PRIVATE StockUtils_lib)


set_target_properties (
    LightBar_lib PROPERTIES
    CXX_STANDARD 17
    )

find_package (Threads)

target_include_directories(LightBar_lib PUBLIC ../third-party/rpi-rgb-led-matrix/include)
target_link_libraries(LightBar_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../third-party/rpi-rgb-led-matrix/lib/librgbmatrix.a ${CMAKE_THREAD_LIBS_INIT})

 add_custom_target(copy-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/media
    ${CMAKE_BINARY_DIR}/media
    )


# TODO: Add tests and install targets if needed.
