add_library(libblx display.c draw.c event.c)
target_link_libraries(libblx PUBLIC X11 compiler_flags)
target_include_directories(libblx PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS libblx DESTINATION lib)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/blx/blx.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/types.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/color.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/display.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/draw.h"
              "${CMAKE_CURRENT_SOURCE_DIR}/blx/event.h"
        DESTINATION include/blx
       )
