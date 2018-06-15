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
    /usr/local/include/glog
    /usr/local/include/glog/include
    /usr/include
    /usr/include/${CMAKE_LIBRARY_ARCHITECTURE}
    /usr/local/include
    /sw/include
    /opt/local/include )

find_path (GLOG_INCLUDE_DIR    logging.h
           PATHS ${GENERIC_INCLUDE_PATHS}  NO_DEFAULT_PATH)


set (GENERIC_LIBRARY_PATHS
    ${GENERIC_LIBRARY_PATHS}
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
    MESSAGE(FATAL_ERROR  "GLOG NOT FOUND!!" ${GLOG_LIBRARY_RELEASE})
endif ()