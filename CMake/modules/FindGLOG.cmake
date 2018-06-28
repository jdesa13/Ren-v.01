# - Try to find GLOG  lib
#
# Once done this will define
#
#  GLOG_FOUND - system has GLOG lib with correct version
#  GLOG_INCLUDE_DIR - the GLOG include directory
#  GLOG_LIBRARIES - the GLOG library

# Other standarnd issue macros
include (FindPackageHandleStandardArgs)
include (SelectLibraryConfigurations)

set (GENERIC_INCLUDE_PATHS
    ${GLOG_CUSTOM_INCLUDE_DIR}
    ${GLOG_CUSTOM_INCLUDE_DIR}/glog
    ${GLOG_CUSTOM_INCLUDE_DIR}/glog/src
    ${GLOG_CUSTOM_LIB_DIR}/
    /usr/local/include/glog
    /usr/local/include/glog/include
    /usr/include
    /usr/include/${CMAKE_LIBRARY_ARCHITECTURE}
    /usr/local/include
    /sw/include
    /opt/local/include )

if(WIN32)
   SET(GENERIC_INCLUDE_PATHS ${GENERIC_INCLUDE_PATHS} ${GLOG_CUSTOM_INCLUDE_DIR}/glog/src/windows/glog)
endif()

find_path (GLOG_INCLUDE_DIR    logging.h
           PATHS ${GENERIC_INCLUDE_PATHS}  NO_DEFAULT_PATH)

if(WIN32)
    get_filename_component(GLOGBASE_PATH ${GLOG_INCLUDE_DIR} PATH)
    set(GLOG_INCLUDE_DIR ${GLOG_INCLUDE_DIR} ${GLOGBASE_PATH})
endif()

set (GENERIC_LIBRARY_PATHS
    ${GENERIC_LIBRARY_PATHS}
    ${GLOG_CUSTOM_LIB_DIR}
    ${GLOG_CUSTOM_LIB_DIR}/Debug
    ${GLOG_CUSTOM_LIB_DIR}/Release
    ${GLOG_CUSTOM_LIB_DIR}/lib
    /usr/lib
    /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /usr/local/lib
    /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /sw/lib
    /opt/local/lib )


include(${CMAKE_SOURCE_DIR}/CMake/SelectLibraryConfigurations.cmake)
set (_glog_components_release glog )
set (_glog_components_debug glogd  )

foreach (COMPONENT ${_glog_components_release})
    find_library (GLOG_LIBRARY_RELEASE ${COMPONENT}
                  PATHS ${GENERIC_LIBRARY_PATHS} NO_DEFAULT_PATH)
endforeach ()

foreach (COMPONENT ${_glog_components_debug})
    find_library (GLOG_LIBRARY_DEBUG ${COMPONENT}
                  PATHS ${GENERIC_LIBRARY_PATHS} NO_DEFAULT_PATH)
endforeach ()


if (GLOG_INCLUDE_DIR AND GLOG_LIBRARY_RELEASE)
    set (GLOG_FOUND TRUE)
    select_library_configurations(GLOG)
else()
    if(NOT WIN32)
      MESSAGE("Did you make install !!!-----")
    endif()
    MESSAGE(STATUS "Include: " ${GLOG_INCLUDE_DIR})
    MESSAGE(STATUS "libs: " ${GLOG_LIBRARY_RELEASE})
    MESSAGE(FATAL_ERROR  "GLOG NOT FOUND!!" ${GLOG_LIBRARY_RELEASE})

endif ()