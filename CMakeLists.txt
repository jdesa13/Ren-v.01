cmake_minimum_required(VERSION 2.8.9)
project (RendererV.01)

if(WIN32)
  set(EXTERNAL_PATH_ROOT "c:/CODE/ExternalLibraries" CACHE STRING
    "My include dir. Must be absolute path (NOT relative.
    You may add additional search paths here. Use ; to separate multiple paths.")
  set(EXTERNAL_PATH_BUILD_FOLDER "build_windows")
else()
  set(EXTERNAL_PATH_ROOT "/mnt/c/CODE/ExternalLibraries" CACHE STRING
    "My include dir. Must be absolute path (NOT relative.
    You may add additional search paths here. Use ; to separate multiple paths.")
  set(EXTERNAL_PATH_BUILD_FOLDER "build_linux")
endif()

MESSAGE(STATUS "EXTERNAL PATH ROOT is set to: " ${EXTERNAL_PATH_ROOT})

if(MSVC)
   set(EXTERNALLIBRARIES "${EXTERNAL_PATH_ROOT}/${EXTERNAL_PATH_BUILD_FOLDER}/Release" "${EXTERNAL_PATH_ROOT}/${EXTERNAL_PATH_BUILD_FOLDER}/Debug" CACHE PATH "Directory where lib files are located" FORCE)
else()
   set(EXTERNALLIBRARIES "${EXTERNAL_PATH_ROOT}/${EXTERNAL_PATH_BUILD_FOLDER}" CACHE PATH "Directory where lib files are located" FORCE)
endif()

set(EXTERNALINCLUDES "${EXTERNAL_PATH_ROOT}/external_libraries" )

set(CMAKE_MODULE_PATH
  ${CMAKE_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/modules
  ${CMAKE_MODULE_PATH}
  )

##############################################################
# Output paths
##############################################################
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Sanitize build environment for static build with C++11
if (MSVC)
  # Disable annoying secure CRT warnings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_WARNINGS")

  # We'll select the TBB library ourselves
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D__TBB_NO_IMPLICIT_LINKAGE")

  # Parallel build on MSVC (all targets)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

  if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE2")

    # Disable Eigen vectorization for Windows 32 bit builds (issues with unaligned access segfaults)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DEIGEN_DONT_ALIGN")
  endif()

  # Static build
  set(CompilerFlags
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  endforeach()
elseif(APPLE)
  # Try to auto-detect a suitable SDK
  execute_process(COMMAND bash -c "xcodebuild -version -sdk | grep MacOSX | grep Path | head -n 1 | cut -f 2 -d ' '" OUTPUT_VARIABLE CMAKE_OSX_SYSROOT)
  string(REGEX REPLACE "(\r?\n)+$" "" CMAKE_OSX_SYSROOT "${CMAKE_OSX_SYSROOT}")
  string(REGEX REPLACE "^.*X([0-9.]*).sdk$" "\\1" CMAKE_OSX_DEPLOYMENT_TARGET "${CMAKE_OSX_SYSROOT}")
endif()

set(BASS_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/include/)
	
set(REN_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Renderer)
	
set(SCR_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Screen)
	
set(CAM_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Camera)
 
set(OBJ_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Objects)

set(MAT_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Material)
	
set(LIT_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Light)
	
set(ING_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Integrator)
	
set(FILM_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Film)
	
set(CORE_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/src/Core)
	
add_definitions(-D_USE_MATH_DEFINES)
add_subdirectory(src/Renderer)
add_subdirectory(src/Screen)
add_subdirectory(src/Camera)
add_subdirectory(src/Objects)
add_subdirectory(src/Material)
add_subdirectory(src/Light)
add_subdirectory(src/Integrator)
add_subdirectory(src/Film)
add_subdirectory(src/Core)
					

MESSAGE(STATUS "...Searching for Dependencies in : " ${EXTERNALLIBRARIES})

set(ZLIB_ROOT ${EXTERNALLIBRARIES} ${EXTERNALINCLUDES}/zlib)
find_package(ZLIB REQUIRED)
Message(STATUS " ZLIB has been found... " ${ZLIB_FOUND})
Message(STATUS " ZLIB version: " ${ZLIB_VERSION_STRING})
Message(STATUS " -ZLIB_INCLUDE_DIRS is set to: " ${ZLIB_INCLUDE_DIRS})
Message(STATUS " -ZLIB_LIBRARIES is set to: " ${ZLIB_LIBRARIES})

set(OPENEXR_CUSTOM_LIB_DIR ${EXTERNALLIBRARIES})
set(OPENEXR_CUSTOM_INCLUDE_DIR ${EXTERNALINCLUDES}/openexr)
set(ILMBASE_INCLUDE_PATH ${EXTERNALINCLUDES}/openexr/IlmBase)
set(OPENEXR_INCLUDE_PATH ${EXTERNALINCLUDES}/openexr)
find_package(OpenEXR REQUIRED)
Message(STATUS " OPENEXR has been found... " ${OpenEXR_FOUND})
Message(STATUS " OPENEXR version: " ${OPENEXR_VERSION})
Message(STATUS " -OPENEXR_LIBRARIES is set to: " ${OPENEXR_LIBRARIES})
Message(STATUS " -OPENEXR_INCLUDE_DIRS is set to: " ${OPENEXR_INCLUDE_DIR})
Message(STATUS " -ILMBASE_INCLUDE_DIRS is set to: " ${ILMBASE_INCLUDE_DIR})

set(EIGEN3_ROOT ${EXTERNALINCLUDES})
find_package(Eigen3 REQUIRED)
Message(STATUS " EIGEN3 has been found... " ${EIGEN3_FOUND})
Message(STATUS " EIGEN3 version: " ${EIGEN3_VERSION})
Message(STATUS " -EIGEN3_INCLUDE_DIR is set to: " ${EIGEN3_INCLUDE_DIR})


set(RAPIDJSON_INCLUDEDIR ${EXTERNALINCLUDES})
set(RAPIDJSON_USE_SSE2  ON)
find_package(rapidjson REQUIRED)
Message(STATUS " RAPIDJSON has been found... " ${RAPIDJSON_FOUND})
Message(STATUS " RAPIDJSON Extra C++ flags : " ${RAPIDJSON_CXX_FLAGS})
Message(STATUS " -RAPIDJSON_INCLUDE_DIR is set to: " ${RAPIDJSON_INCLUDE_DIRS})

set(STB_ROOT ${EXTERNALINCLUDES})
find_package(STB REQUIRED)
Message(STATUS " STB has been found... " ${STB_FOUND})
Message(STATUS " -STB_INCLUDE_DIR is set to: " ${STB_INCLUDE_DIR})

if(MSVC)
    file(GLOB resources "${EXTERNAL_PATH_ROOT}/${EXTERNAL_PATH_BUILD_FOLDER}/Release/*.dll")
    file(COPY ${resources}     DESTINATION ${CMAKE_BINARY_DIR}/Release)
    file(GLOB resourcesd "${EXTERNAL_PATH_ROOT}/${EXTERNAL_PATH_BUILD_FOLDER}/Debug/*.dll")
    file(COPY ${resourcesd}     DESTINATION ${CMAKE_BINARY_DIR}/Debug)
endif()
		
include_directories(${BASS_INCLUDE_DIR} ${CAM_INCLUDE_DIR} 
                    ${REN_INCLUDE_DIR} ${SCR_INCLUDE_DIR}
					${EIGEN3_INCLUDE_DIR} ${OBJ_INCLUDE_DIR}
					${MAT_INCLUDE_DIR}  ${LIT_INCLUDE_DIR}
					${ING_INCLUDE_DIR} ${OPENEXR_INCLUDE_DIR}
					${RAPIDJSON_INCLUDE_DIRS}${FILM_INCLUDE_DIR}
					${ILMBASE_INCLUDE_DIR} ${ZLIB_INCLUDE_DIRS}
					${CORE_INCLUDE_DIR} ${STB_INCLUDE_DIR})
		
add_executable(Renderer_Tester main.cpp)

target_link_libraries(Renderer_Tester Renderer Screen 
                      Camera Objects Material Light
					  Integrator Film ${ZLIB_LIBRARIES} ${OPENEXR_LIBRARIES}
					  Core)

ADD_DEPENDENCIES(Renderer_Tester Renderer Screen
                 Camera Objects Material Light
				 Integrator Film Core)