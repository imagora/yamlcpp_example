cmake_minimum_required(VERSION 3.2)
project(yamlcpp_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/opt/yaml-cpp/include/)
link_directories(/usr/local/opt/yaml-cpp/lib)

link_libraries(yaml-cpp)

set(SOURCE_FILES main.cpp read_write.cpp)
add_executable(yamlcpp_example ${SOURCE_FILES})
