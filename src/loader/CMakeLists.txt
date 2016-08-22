set(SOURCES
	include/loader/image.h
	include/loader/mesh.h
	include/loader/submesh.h

	src/image.cpp
	src/mesh.cpp
	src/submesh.cpp
)

INCLUDE_DIRECTORIES("include")
INCLUDE_DIRECTORIES("../gpu/include")
ADD_LIBRARY(loader ${SOURCES})


