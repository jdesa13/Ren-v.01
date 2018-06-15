include_directories(
   ${BASS_INCLUDE_DIR}
   ${REN_INCLUDE_DIR}
   ${EIGEN3_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)


set(ING_SRCS
	${BASS_INCLUDE_DIR}/Bass/hit.h hit.cpp
	${BASS_INCLUDE_DIR}/Bass/integrator.h integrator.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Integrator ${LIB_TYPE} ${ING_SRCS})