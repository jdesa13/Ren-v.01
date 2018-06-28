# Defines:
# TFORMAT_FOUND
# TFORMAT_INCLUDE_DIR
#

if (TFORMAT_LIBRARY AND TFORMAT_INCLUDE_DIR)
    set(TFORMAT_FOUND TRUE)
else (TFORMAT_LIBRARY AND TFORMAT_INCLUDE_DIR)

  SET (TFORMAT_ADDITIONAL_SEARCH_PATHS ${TFORMAT_ADDITIONAL_SEARCH_PATHS} ${TFORMAT_ROOT} ${TFORMAT_ROOT}/tinyformat ${TFORMAT_ROOT}/tinyformat/include )

  # specific additional paths for some OS
  SET(TFORMAT_ADDITIONAL_SEARCH_PATHS ${TFORMAT_ADDITIONAL_SEARCH_PATHS} 
      /usr/include 
      /usr/local/include 
      /opt/local/include
      /sw/include
      /usr/include/tinyformat
      /usr/local/include/tinyformat
      /opt/local/include/tinyformat
      )

  find_path(TFORMAT_INCLUDE_DIR
    NAMES tinyformat.h
    PATHS ${TFORMAT_ADDITIONAL_SEARCH_PATHS} 
    PATH_SUFFIXES tinyformat
  )


  if (TFORMAT_INCLUDE_DIR)
    set(TFORMAT_FOUND TRUE)
  endif()

endif ()
