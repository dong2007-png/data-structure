cmake_minimum_required(VERSION 3.20)
project(data_structure)

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 解决中文乱码
add_compile_options(-fexec-charset=UTF-8)

# 自动递归查找所有 cpp 文件（不用手动一个个加！）
file(GLOB_RECURSE ALL_SOURCES
        *.cpp
        **/*.cpp
        */*.cpp
)

# 生成可执行文件
add_executable(data_structure ${ALL_SOURCES})