include_directories(
   ${BASS_INCLUDE_DIR}
   ${REN_INCLUDE_DIR}
   ${EIGEN3_INCLUDE_DIR}
   ${OPENEXR_INCLUDE_DIR}
   ${ILMBASE_INCLUDE_DIR}
   ${ZLIB_INCLUDE_DIRS}
   ${STB_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)


set(FILM_SRCS
	${BASS_INCLUDE_DIR}/Bass/film.h film.cpp
	${BASS_INCLUDE_DIR}/Bass/hdrfilm.h hdrfilm.cpp
	${BASS_INCLUDE_DIR}/Bass/ldrfilm.h ldrfilm.cpp)
	
SET(LIB_TYPE STATIC)

add_library(Film ${LIB_TYPE} ${FILM_SRCS})