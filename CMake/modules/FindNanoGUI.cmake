#
# Try to find NANOGUI library and include path.
# Once done this will define
#
# NANOGUI_FOUND
# NANOGUI_INCLUDE_DIR
# NANOGUI_LIBRARY
#

if(NOT NANOGUI_FOUND)

FIND_PATH(NANOGUI_INCLUDE_DIR nanogui/nanogui.h
  PATHS
    ${NANOGUI_ROOT}/nanogui/
    ${NANOGUI_ROOT}/nanogui/include
    ${NANOGUI_ROOT}/nanogui/include/nanogui
      /usr/include 
      /usr/X11/include
      /usr/local/include 
      /opt/local/include
      /usr/include/nanogui
      /usr/include/nanogui/include
      /usr/local/include/nanogui
      /opt/local/include/nanogui
      /opt/local/include/nanogui/include
     NO_DEFAULT_PATH
    )


set(GENERIC_LIBRARY_PATHS 
    ${NANOGUI_CUSTOM_LIB_DIR}
    ${NANOGUI_CUSTOM_LIB_DIR}/nanogui/build
    ${NANOGUI_CUSTOM_LIB_DIR}/Debug
    ${NANOGUI_CUSTOM_LIB_DIR}/Release
    /usr/lib
    /usr/local
    /usr/local/lib
    /usr/X11
    /usr
    /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /sw/lib
    /opt/local/lib  )


FIND_LIBRARY( NANOGUI_LIBRARY_RELEASE NAMES nanogui
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

FIND_LIBRARY( NANOGUI_LIBRARY_DEBUG NAMES nanoguid
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

select_library_configurations(NANOGUI)



SET(NANOGUI_FOUND "NO")
IF (NANOGUI_INCLUDE_DIR AND NANOGUI_LIBRARY)
	SET(NANOGUI_FOUND  TRUE)
  SET(NANOGUI_INCLUDE_DIRS
         ${NANOGUI_INCLUDE_DIR}
         ${NANOGUI_ROOT}/nanogui/ext/nanovg/src
         ${NANOGUI_ROOT}/nanogui/ext/glfw/include
         ${NANOGUI_ROOT}/nanogui/ext/glad/include
         )

ENDIF (NANOGUI_INCLUDE_DIR AND NANOGUI_LIBRARY)

if(NANOGUI_FOUND)
  message(STATUS "Found NANOGUI: ${NANOGUI_INCLUDE_DIR}")
else(NANOGUI_FOUND)
  if (NOT NANOGUI_FIND_QUIETLY)
    message(FATAL_ERROR "could NOT find NANOGUI")
  endif (NOT NANOGUI_FIND_QUIETLY)
endif(NANOGUI_FOUND)

endif(NOT NANOGUI_FOUND)