include_directories(
   ${BASS_INCLUDE_DIR}
   )

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

set(REND_SRCS
    ${BASS_INCLUDE_DIR}/Bass/render.h render.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Renderer ${LIB_TYPE} ${REND_SRCS})
	

