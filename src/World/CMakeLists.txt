include_directories(
   ${BASS_INCLUDE_DIR}
   )

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

set(WORLD_SRCS
    ${BASS_INCLUDE_DIR}/Bass/world.h world.cpp)
	
SET(LIB_TYPE STATIC)

add_library(world ${LIB_TYPE} ${WORLD_SRCS})