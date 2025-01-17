cmake_minimum_required(VERSION 3.25.1)

project(BelenuX
        VERSION 1.0
        DESCRIPTION "X11 based graphic library"
        LANGUAGES C)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE c_std_90)

set(gcc_like_c "$<COMPILE_LANG_AND_ID:C,GNU>")
target_compile_options(compiler_flags INTERFACE
    "$<${gcc_like_c}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wwrite-strings;-Wstrict-prototypes;-Wunreachable-code;-Werror>>")

add_subdirectory(libblx)

add_subdirectory(blxhw)
