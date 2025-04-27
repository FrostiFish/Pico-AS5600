add_library(pico_i2c_helpers INTERFACE)

target_sources(pico_i2c_helpers INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/i2c_helpers.c
)

target_include_directories(pico_i2c_helpers INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Add the used pico libraries to the library
target_link_libraries(pico_i2c_helpers INTERFACE
        pico_stdlib
        hardware_i2c)
