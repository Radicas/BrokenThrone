# 设置最小cmake版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目信息
project(BrokenThrone
        VERSION 0.4.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 收集源文件
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

# 添加头文件目录
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory(src)
