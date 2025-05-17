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

# 复制资源文件到build的exe目录下，让运行时代码可以相对路径检查
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
