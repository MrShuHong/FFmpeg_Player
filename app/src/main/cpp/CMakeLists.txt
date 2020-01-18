
cmake_minimum_required(VERSION 3.4.1)

file(GLOB allcpp *.cpp)

add_library(
        md_player

        SHARED

        ${allcpp})

find_library(
        log-lib
        log)
# 导入ffmpeg头文件
include_directories(${CMAKE_SOURCE_DIR}/ffmpeg/include)
# 导入ffmpeg库文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/ffmpeg/libs/${CMAKE_ANDROID_ARCH_ABI}")
# 导入RTMP库文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/rtmp/libs/${CMAKE_ANDROID_ARCH_ABI}")

target_link_libraries(
        md_player
        -Wl,--start-group
        avcodec avfilter avformat avutil swresample swscale
        -Wl,--end-group
        ${log-lib}
        z
)