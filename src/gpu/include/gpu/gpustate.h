#pragma once

#include "gpu.h"

namespace Gpu {

	static void gpuActiveState(GLenum state) { glEnable(state); OGLERROR; }

}