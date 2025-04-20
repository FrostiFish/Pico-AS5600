add_library(pico_as5600 INTERFACE)

target_sources(pico_as5600 INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/AS5600.c
)

target_include_directories(pico_as5600 INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Add the used pico libraries to the library
target_link_libraries(pico_as5600 INTERFACE
        pico_stdlib
        hardware_i2c)
