add_executable(blxcalc start.c node.c stack.c queue.c)
target_link_libraries(blxcalc PUBLIC blx compiler_flags)
target_include_directories(blxcalc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
