# 收集源文件
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 添加头文件目录
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# 编译成库
add_executable(${PROJECT_NAME}
        ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
)



