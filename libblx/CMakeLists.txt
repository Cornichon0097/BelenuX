configure_file("${CMAKE_CURRENT_SOURCE_DIR}/blx/version.h.in"
               "${CMAKE_CURRENT_SOURCE_DIR}/blx/version.h")

add_library(blx frame.c color.c draw.c event.c)
target_link_libraries(blx PUBLIC X11 compiler_flags)
target_include_directories(blx PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS blx DESTINATION lib)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/blx/blx.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/version.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/types.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/frame.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/color.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/draw.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/event.h"
        DESTINATION include/blx)
