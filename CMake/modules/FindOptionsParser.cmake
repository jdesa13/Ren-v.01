# Defines:
# OPTIONS_FOUND
# OPTIONS_INCLUDE_DIR
#

if (OPTIONS_LIBRARY AND OPTIONS_INCLUDE_DIR)
    set(OPTIONS_FOUND TRUE)
else (OPTIONS_LIBRARY AND OPTIONS_INCLUDE_DIR)

  SET (OPTIONS_ADDITIONAL_SEARCH_PATHS ${OPTIONS_ADDITIONAL_SEARCH_PATHS} ${OPTIONS_ROOT} ${OPTIONS_ROOT}/optionparser/src ${OPTIONS_ROOT}/optionparser ${OPTIONS_ROOT}/optionparser/include )

  # specific additional paths for some OS
  SET(OPTIONS_ADDITIONAL_SEARCH_PATHS ${OPTIONS_ADDITIONAL_SEARCH_PATHS} 
      /usr/include 
      /usr/local/include 
      /opt/local/include
      /sw/include
      /usr/include/optionparser
      /usr/local/include/optionparser
      /opt/local/include/optionparser
      )

  find_path(OPTIONS_INCLUDE_DIR
    NAMES optionparser.h
    PATHS ${OPTIONS_ADDITIONAL_SEARCH_PATHS} 
    PATH_SUFFIXES optionparser
  )


  if (OPTIONS_INCLUDE_DIR)
    set(OPTIONS_FOUND TRUE)
  endif()

endif ()
