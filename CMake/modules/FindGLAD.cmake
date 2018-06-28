#
# Try to find GLAD library and include path.
# Once done this will define
#
# GLAD_FOUND
# GLAD_INCLUDE_DIR
# GLAD_LIBRARIES
#

if(NOT GLAD_FOUND)

  FIND_PATH(GLAD_INCLUDE_DIR glad/glad.h
    PATHS
      ${GLAD_ROOT}/glad/
      ${GLAD_ROOT}/glad/include
      ${GLAD_ROOT}/glad/include/glad
        /usr/include 
        /usr/X11/include
        /usr/local/include 
        /opt/local/include
        /usr/include/glad
        /usr/include/glad/include
        /usr/local/include/glad
        /opt/local/include/glad
        /opt/local/include/glad/include
       NO_DEFAULT_PATH
      )
  

set(GENERIC_LIBRARY_PATHS 
    ${GLAD_CUSTOM_LIB_DIR}
    ${GLAD_CUSTOM_LIB_DIR}/glfw/build
    ${GLAD_CUSTOM_LIB_DIR}/Debug
    ${GLAD_CUSTOM_LIB_DIR}/Release
    /usr/lib
    /usr/local
    /usr/local/lib
    /usr/X11
    /usr
    /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /sw/lib
    /opt/local/lib   )

FIND_LIBRARY( GLAD_LIBRARY_RELEASE NAMES glad
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

FIND_LIBRARY( GLAD_LIBRARY_DEBUG NAMES gladd
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

select_library_configurations(GLAD)
SET(GLAD_LIBRARIES  ${GLAD_LIBRARY} )




  
  SET(GLAD_FOUND "NO")
  IF (GLAD_INCLUDE_DIR AND GLAD_LIBRARIES)
  	SET(GLAD_FOUND TRUE)
  ENDIF ()
  
  
  if(GLAD_FOUND)
  else()
    if (NOT GLAD_FIND_QUIETLY)
      message( ${GLAD_INCLUDE_DIR})
      message( ${GLAD_LIBRARY})
      message(FATAL_ERROR "could NOT find GLAD")
    endif ()
  endif()

endif()