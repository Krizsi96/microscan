cmake_minimum_required(VERSION 3.29)
project(microscan)

set(CMAKE_CXX_STANDARD 23)

add_executable(microscan main.cpp)

target_link_libraries(microscan PUBLIC /usr/local/lib/libsick_safetyscanners_base.so)