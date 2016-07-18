set(SOURCES
	include/loader/image.h
	include/loader/mesh.h
	include/loader/submesh.h

	src/image.cpp
	src/mesh.cpp
	src/submesh.cpp
)

INCLUDE_DIRECTORIES("include")
ADD_LIBRARY(loader ${SOURCES})


