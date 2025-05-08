# 设置最小cmake版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目信息
project(GraphicsLab
        VERSION 0.4.0
        LANGUAGES C CXX
)

# 设置当前cmake路径为主路径
set(CMAKE_HOME_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# 自动生成版本文件
configure_file(${CMAKE_HOME_PATH}/src/version.h.in ${CMAKE_HOME_PATH}/inc/graphicslab/version.h)

set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# 设置安装路径
set(INSTALL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/install)

# 头文件目录
set(HEADERS_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${THIRD_PARTY_PATH}/glad/include
        ${CMAKE_SOURCE_DIR}/submodule/redcgl/inc
)

# 源文件目录
set(SOURCES_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${THIRD_PARTY_PATH}/glad/src
)

add_subdirectory(submodule/redcgl)

# 库源文件
add_subdirectory(src)

# # 单元测试
# add_subdirectory(test_googletest)

# ## 性能测试
# add_subdirectory(test_benchmark)

# ####### 自定义安装 ########
# 获取自仓库编译好的动态库
file(GLOB_RECURSE DLL
        ${CMAKE_SOURCE_DIR}/submodule/redcgl/install/*
        ${CMAKE_SOURCE_DIR}/submodule/redcgl/submodule/install*
)

# 将当前动态库安装到install
install(FILES ${DLL} DESTINATION
        ${CMAKE_SOURCE_DIR}/install/bin
)

# message(STATUS "REDEDA_DEV_DIST path:" ${REDEDA_DEV_DIST})

# if(REDEDA_DEV_DIST)
# # 将当前动态库安装到DEV_DIST
# install(FILES ${DLL} DESTINATION
# ${REDEDA_DEV_DIST}
# )

# # 获取头文件
# set(INC ${CMAKE_HOME_PATH}/inc/redcgl)

# # 将头文件安装到DEV_DIST
# install(DIRECTORY ${INC} DESTINATION
# ${REDEDA_DEV_DIST}/rededa/include/rededa
# )
# endif ()
# #########################