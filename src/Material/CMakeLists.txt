include_directories(
   ${BASS_INCLUDE_DIR}
   ${REN_INCLUDE_DIR}
   ${EIGEN3_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)


set(MAT_SRCS
	${BASS_INCLUDE_DIR}/Bass/material.h material.cpp
	${BASS_INCLUDE_DIR}/Bass/diffuse.h diffuse.cpp
	${BASS_INCLUDE_DIR}/Bass/phong.h phong.cpp
	${BASS_INCLUDE_DIR}/Bass/ambient.h ambient.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Material ${LIB_TYPE} ${MAT_SRCS})