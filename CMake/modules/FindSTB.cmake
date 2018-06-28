# Defines:
# STB_FOUND
# STB_INCLUDE_DIR
# STB_LIBRARY #optional - turned off for now.
#

if (STB_LIBRARY AND STB_INCLUDE_DIR)
    set(STB_FOUND TRUE)
else (STB_LIBRARY AND STB_INCLUDE_DIR)

  SET (STB_ADDITIONAL_SEARCH_PATHS ${STB_ADDITIONAL_SEARCH_PATHS} ${STB_ROOT} ${STB_ROOT}/stb ${STB_ROOT}/stb/include )

  # specific additional paths for some OS
  SET(STB_ADDITIONAL_SEARCH_PATHS ${STB_ADDITIONAL_SEARCH_PATHS} 
      /usr/include 
      /usr/local/include 
      /opt/local/include
      /sw/include
      /usr/include/stb
      /usr/local/include/stb
      /opt/local/include/stb
      )

  find_path(STB_INCLUDE_DIR
    NAMES stb_image.h
    PATHS ${STB_ADDITIONAL_SEARCH_PATHS} 
    PATH_SUFFIXES stbi stb
  )

 #find_library(STBI_LIBRARY
 #   NAMES stbi stb
 #   PATHS ${_STBI_LIBRARY_DIRS} /usr/lib /usr/local/lib /opt/local/lib /sw/lib
 # )

  if (STB_INCLUDE_DIR)
    set(STB_FOUND TRUE)
  endif()

endif ()
