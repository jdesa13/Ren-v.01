# Defines:
# TINYOBJ_FOUND
# TINYOBJ_INCLUDE_DIR
#

if (TINYOBJ_LIBRARY AND TINYOBJ_INCLUDE_DIR)
    set(STB_FOUND TRUE)
else (TINYOBJ_LIBRARY AND TINYOBJ_INCLUDE_DIR)

  SET (TINYOBJ_ADDITIONAL_SEARCH_PATHS ${TINYOBJ_ADDITIONAL_SEARCH_PATHS} ${TINYOBJ_ROOT} ${TINYOBJ_ROOT}/tinyobjloader ${TINYOBJ_ROOT}/tinyobjloader/include )

  # specific additional paths for some OS
  SET(TINYOBJ_ADDITIONAL_SEARCH_PATHS ${TINYOBJ_ADDITIONAL_SEARCH_PATHS} 
      /usr/include 
      /usr/local/include 
      /opt/local/include
      /sw/include
      /usr/include/tinyobjloader
      /usr/local/include/tinyobjloader
      /opt/local/include/tinyobjloader
      )

  find_path(TINYOBJ_INCLUDE_DIR
    NAMES tiny_obj_loader.h
    PATHS ${TINYOBJ_ADDITIONAL_SEARCH_PATHS} 
    PATH_SUFFIXES tiny_obj_loader tinyobjloader
  )



  if (TINYOBJ_INCLUDE_DIR)
    set(TINYOBJ_FOUND TRUE)
  endif()

endif ()
