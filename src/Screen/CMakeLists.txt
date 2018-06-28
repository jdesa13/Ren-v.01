include_directories(
   ${BASS_INCLUDE_DIR}
   ${REN_INCLUDE_DIR}
   ${EIGEN3_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

set(SCR_SRCS
    ${BASS_INCLUDE_DIR}/Bass/screen.h screen.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Screen ${LIB_TYPE} ${SCR_SRCS})	