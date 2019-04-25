# Wrapper for generating binary interpreters via Cheetah: http://cheetahtemplate.org/

# Cache this script file directory path.
set(add_cheetah_generator_script_dir ${CMAKE_CURRENT_LIST_DIR} CACHE INTERNAL "")

find_program(add_cheetah_generator_script_python NAMES python3 python )
if (add_cheetah_generator_script_python)
    message(STATUS "Python found: ${add_cheetah_generator_script_python}")
else ()
    message(FATAL_ERROR "Failed to find python")
endif ()

# add_cheetah_generator(
#     TARGET_NAME ${myprj}                  # Name of the target that involves generation.
#     TEMPLATE  "protocol_message.tmpl.hpp" # Cheetah template.
#     OUTPUT_DIR "include/protocol"         # Directory for output files.
#     INPUT                                 # Input parameters for generated code.
#       "data_structs/message_header.json"
#       "data_structs/message_x.json"
#       "data_structs/message_y.json"
#       # ...
# )
function (add_cheetah_generator)
    set(one_value_args TARGET_NAME TEMPLATE OUTPUT_DIR)
    set(multi_value_args INPUT )
    cmake_parse_arguments(cheetah "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    message( STATUS "inputs: ${cheetah_INPUT}")
    foreach ( input_file ${cheetah_INPUT} )
        get_filename_component( base_file_name ${input_file} NAME_WE )
        set(output_file "${cheetah_OUTPUT_DIR}/${base_file_name}.hpp")
        list(APPEND outputs_files ${output_file})


        set(run_cheetah ${add_cheetah_generator_script_dir}/run_cheetah.py )
        add_custom_command(
            COMMAND ${add_cheetah_generator_script_python} ${run_cheetah} ${cheetah_TEMPLATE} ${cheetah_OUTPUT_DIR} ${input_file}
            DEPENDS  ${run_cheetah} ${cheetah_TEMPLATE} ${input_file}
            OUTPUT ${output_file}
            COMMENT "Run code generation using ${cheetah_TEMPLATE} for ${input_file} to ${cheetah_OUTPUT_DIR}"
        )
    endforeach ()

    message( STATUS "add_cheetah_generator '${cheetah_TARGET_NAME}' DEPENDS: ${outputs_files}")
    add_custom_target(${cheetah_TARGET_NAME} DEPENDS ${outputs_files} )
endfunction ()
