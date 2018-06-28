#
# Try to find GLFW library and include path.
# Once done this will define
#
# GLFW_FOUND
# GLFW_INCLUDE_DIR
# GLFW_LIBRARIES
#

if(NOT GLFW_FOUND)

FIND_PATH(GLFW_INCLUDE_DIR GLFW/glfw3.h
  PATHS
    ${GLFW_ROOT}/glfw/
    ${GLFW_ROOT}/glfw/include
    ${GLFW_ROOT}/glfw/include/glfw
      /usr/include 
      /usr/X11/include
      /usr/local/include 
      /opt/local/include
      /usr/include/glfw
      /usr/include/glfw/include
      /usr/local/include/glfw
      /opt/local/include/glfw
      /opt/local/include/glfw/include
     NO_DEFAULT_PATH
    )

set(GENERIC_LIBRARY_PATHS 
    ${GLFW_CUSTOM_LIB_DIR}
    ${GLFW_CUSTOM_LIB_DIR}/glfw/build
    ${GLFW_CUSTOM_LIB_DIR}/Debug
    ${GLFW_CUSTOM_LIB_DIR}/Release
    /usr/lib
    /usr/local
    /usr/local/lib
    /usr/X11
    /usr
    /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /sw/lib
    /opt/local/lib   )

FIND_LIBRARY( GLFW_LIBRARY_RELEASE NAMES glfw glfw3
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

FIND_LIBRARY( GLFW_LIBRARY_DEBUG NAMES glfwd glfw3d
  PATHS ${GENERIC_LIBRARY_PATHS}
    PATH_SUFFIXES
    a
    lib64
    lib
    NO_DEFAULT_PATH)

select_library_configurations(GLFW)
SET(GLFW_LIBRARIES  ${GLFW_LIBRARY} )


SET(GLFW_FOUND "NO")
IF (GLFW_INCLUDE_DIR AND GLFW_LIBRARIES)
	SET(GLFW_FOUND TRUE)
ENDIF (GLFW_INCLUDE_DIR AND GLFW_LIBRARIES)


set(GL_EXTRA_LIBS "")
set(GL_EXTRA_DEFS "")
set(LIBGL_EXTRA_SOURCE "")

if(GLFW_FOUND)
  message(STATUS "Found GLFW: ${GLFW_INCLUDE_DIR}")


  # Required core libraries on various platforms

if (${CMAKE_SYSTEM_NAME} MATCHES "BSD")
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
  if(${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
    include_directories(/usr/X11R6/include/)
    link_directories(/usr/X11R6/lib)
  endif()
endif()
  
  if (WIN32)
    list(APPEND GL_EXTRA_LIBS opengl32)
    list(APPEND GL_EXTRA_DEFS -DNANOGUI_GLAD)
  elseif (APPLE)
    find_library(cocoa_library Cocoa)
    find_library(opengl_library OpenGL)
    find_library(corevideo_library CoreVideo)
    find_library(iokit_library IOKit)
    list(APPEND GL_EXTRA_LIBS ${cocoa_library} ${opengl_library} ${corevideo_library} ${iokit_library})
    list(APPEND LIBGL_EXTRA_SOURCE src/darwin.mm)
  elseif(CMAKE_SYSTEM MATCHES "Linux" OR CMAKE_SYSTEM_NAME MATCHES "BSD")
    find_package(X11)
    list(APPEND GL_EXTRA_LIBS GL Xxf86vm Xrandr Xinerama Xcursor Xi X11 pthread )
    if (NOT CMAKE_SYSTEM_NAME MATCHES "OpenBSD")
      list(APPEND GL_EXTRA_LIBS rt)
    endif()
    if(CMAKE_SYSTEM MATCHES "Linux")
      list(APPEND GL_EXTRA_LIBS dl)
    endif()
  endif()


else(GLFW_FOUND)
  if (NOT GLFW_FIND_QUIETLY)
  message( ${GLFW_INCLUDE_DIR})
    message(FATAL_ERROR "could NOT find GLFW")
  endif (NOT GLFW_FIND_QUIETLY)
endif(GLFW_FOUND)

endif(NOT GLFW_FOUND)
