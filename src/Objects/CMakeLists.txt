include_directories(
   ${BASS_INCLUDE_DIR}
   ${REN_INCLUDE_DIR}
   ${EIGEN3_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)


set(OBJ_SRCS
    ${BASS_INCLUDE_DIR}/Bass/shape.h shape.cpp
	${BASS_INCLUDE_DIR}/Bass/circle.h circle.cpp
	${BASS_INCLUDE_DIR}/Bass/triangle.h triangle.cpp
	${BASS_INCLUDE_DIR}/Bass/plane.h plane.cpp
	${BASS_INCLUDE_DIR}/Bass/mesh.h mesh.cpp
	${BASS_INCLUDE_DIR}/Bass/box.h box.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Objects ${LIB_TYPE} ${OBJ_SRCS})	