cmake_minimum_required(VERSION 3.25.1)

project(BelenoX
        VERSION 1.0
        DESCRIPTION "X11 based graphic library"
        LANGUAGES C
        )

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wwrite-strings -Wstrict-prototypes -Wunreachable-code -Werror -g")

configure_file(include/version.h.in include/version.h)

add_executable(blx src/start.c)

add_subdirectory(libblx)
target_link_libraries(blx PUBLIC libblx)

target_include_directories(blx PUBLIC
                          "${PROJECT_BINARY_DIR}/include"
                          "${PROJECT_SOURCE_DIR}/libblx"
                          )
