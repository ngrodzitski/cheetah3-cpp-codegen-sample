cmake_minimum_required(VERSION 3.10)

set(sample_app_prj sample_app)

project(${sample_app_prj} CXX)

add_executable(${sample_app_prj} main.cpp)

target_link_libraries(${sample_app_prj} PRIVATE custom_protocol::custom_protocol)

