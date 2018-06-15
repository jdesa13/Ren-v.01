include_directories(
   ${BASS_INCLUDE_DIR}
   ${REN_INCLUDE_DIR}
   ${EIGEN3_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)


set(LIT_SRCS
	${BASS_INCLUDE_DIR}/Bass/lights.h lights.cpp
	${BASS_INCLUDE_DIR}/Bass/point.h point.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Light ${LIB_TYPE} ${LIT_SRCS})