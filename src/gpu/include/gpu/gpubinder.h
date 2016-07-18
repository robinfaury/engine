#pragma once

#include "gpu.h"

namespace Gpu {

	class GpuBinder {
	public:
		virtual void bind() = 0;
		virtual void release() = 0;
	};
}