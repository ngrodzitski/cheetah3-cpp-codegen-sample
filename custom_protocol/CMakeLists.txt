cmake_minimum_required(VERSION 3.10)

set(custom_protocol_prj custom_protocol)

project(${custom_protocol_prj} CXX)

add_cheetah_generator(
    TARGET_NAME protocol_messages
    TEMPLATE  "${CMAKE_CURRENT_LIST_DIR}/templates/message.tmpl.hpp"
    OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/include/custom_protocol"
    INPUT
      "${CMAKE_CURRENT_LIST_DIR}/data_structs/message_header.json"
)

add_library(${custom_protocol_prj} INTERFACE )
add_library(${custom_protocol_prj}::${custom_protocol_prj} ALIAS ${custom_protocol_prj})
add_dependencies(${custom_protocol_prj} protocol_messages)

SET(protocol_include_dir ${CMAKE_CURRENT_LIST_DIR}/include)

message( "protocol_include_dir: ${protocol_include_dir}")

target_include_directories(${custom_protocol_prj} INTERFACE
        $<BUILD_INTERFACE:${protocol_include_dir}>
        $<INSTALL_INTERFACE:include>)

