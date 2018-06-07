include_directories(
   ${BASS_INCLUDE_DIR}
   ${EIGEN_INCLUDE_DIR}
   ${REN_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

set(CAM_SRCS
    ${BASS_INCLUDE_DIR}/Bass/camera.h camera.cpp
	${BASS_INCLUDE_DIR}/Bass/pinhole_camera.h pinhole_camera.cpp)
	
SET(LIB_TYPE STATIC)

add_library(camera ${LIB_TYPE} ${CAM_SRCS})	