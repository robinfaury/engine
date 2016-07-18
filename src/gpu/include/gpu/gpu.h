#include <GL/glew.h>
#include <assert.h>

#ifdef _DEBUG
	#include <iostream>
#endif

#define OGLERROR assert(glGetError() == 0)