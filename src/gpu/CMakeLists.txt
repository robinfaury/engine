set(SOURCES
	include/gpu/gpu.h
	include/gpu/gpubinder.h
	include/gpu/gpugeometry.h
	include/gpu/gpuprogram.h
	include/gpu/gputexture.h
	
	src/gpubinder.cpp
	src/gpugeometry.cpp
	src/gpuprogram.cpp
	src/gputexture.cpp
)

INCLUDE_DIRECTORIES("include")
ADD_LIBRARY(gpu ${SOURCES})

INCLUDE_DIRECTORIES("../loader/include")