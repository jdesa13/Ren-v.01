cmake_minimum_required(VERSION 2.8.9)
project (RendererV.01)

##############################################################
# Output paths
##############################################################
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set(BASS_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/include/)
	
set(REN_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Renderer)
	
set(WORLD_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/World)
	
set(CAM_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Camera)
	
set(EIGEN_INCLUDE_DIR
 ${CMAKE_SOURCE_DIR}/external_libraries/eigen)
	
add_definitions(-D_USE_MATH_DEFINES)
add_subdirectory(src/Renderer)
add_subdirectory(src/World)
add_subdirectory(src/Camera)
add_subdirectory(external_libraries)

include_directories(${BASS_INCLUDE_DIR} ${CAM_INCLUDE_DIR} 
                    ${REN_INCLUDE_DIR} ${WORLD_INCLUDE_DIR}
					${EIGEN_INCLUDE_DIR})

add_executable(Renderer_Tester main.cpp)

target_link_libraries(Renderer_Tester Renderer World Camera)

ADD_DEPENDENCIES(Renderer_Tester Renderer World Camera)