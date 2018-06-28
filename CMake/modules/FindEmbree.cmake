#
# Try to find NANOGUI library and include path.
# Once done this will define
#
# EMBREE_FOUND
# EMBREE_INCLUDE_DIR
# EMBREE_LIBRARY
#

if(NOT EMBREE_FOUND)

FIND_PATH(EMBREE_INCLUDE_DIR embree3/rtcore.h
  PATHS
    ${EMBREE_ROOT}/embree/
    ${EMBREE_ROOT}/embree/include
    ${EMBREE_ROOT}/embree/include/embree3
      /usr/include 
      /usr/X11/include
      /usr/local/include 
      /opt/local/include
      /usr/include/embree
      /usr/include/embree/include
      /usr/local/include/nanogui
      /opt/local/include/embree
      /opt/local/include/embree/include
     NO_DEFAULT_PATH
    )


set(GENERIC_LIBRARY_PATHS 
    ${EMBREE_CUSTOM_LIB_DIR}
    ${EMBREE_CUSTOM_LIB_DIR}/embree/build
    ${EMBREE_CUSTOM_LIB_DIR}/Debug
    ${EMBREE_CUSTOM_LIB_DIR}/Release
    /usr/lib
    /usr/local
    /usr/local/lib
    /usr/X11
    /usr
    /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /sw/lib
    /opt/local/lib  )


FIND_LIBRARY( EMBREE_LIBRARY_RELEASE NAMES embree3
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

FIND_LIBRARY( EMBREE_LIBRARY_DEBUG NAMES embree3d
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

select_library_configurations(EMBREE)



SET(EMBREE_FOUND "NO")
IF (EMBREE_INCLUDE_DIR AND EMBREE_LIBRARY)
	SET(EMBREE_FOUND  TRUE)
  SET(EMBREE_INCLUDE_DIRS
         ${EMBREE_ROOT}/embree/kernels 
         ${EMBREE_ROOT}/embree/common 
         )
ENDIF ()

if(EMBREE_FOUND)
  message(STATUS "Found EMBREE: ${EMBREE_INCLUDE_DIR}")
else(EMBREE_FOUND)
  if (NOT EMBREE_FIND_QUIETLY)
    message(${EMBREE_INCLUDE_DIR})
    message(${EMBREE_LIBRARY})
    message(FATAL_ERROR "could NOT find EMBREE")
  endif ()
endif(EMBREE_FOUND)

endif(NOT EMBREE_FOUND)