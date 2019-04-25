cmake_minimum_required(VERSION 3.10)

set( sample_cheetah_generator_root_prj SampleCheetahCodeGenRootPrj )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(${sample_cheetah_generator_root_prj} CXX)

include("cmake/cheetah_wrapper.cmake")

add_subdirectory( custom_protocol )
add_subdirectory( sample_app )
