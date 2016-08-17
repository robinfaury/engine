#pragma once

#include "gpubinder.h"
#include <loader/image.h>

namespace Gpu {

	class GpuTexture {
	public:
		/*********BINDER***********/
		class ScopedGpuTextureBinder : public GpuBinder {
		public:
			ScopedGpuTextureBinder();
			~ScopedGpuTextureBinder() { release(); }
			void bind() {  OGLERROR; }
			void release() { OGLERROR; }
		};


		/************IMPL***********/
		GpuTexture();
		GpuTexture(const Loader::Image& image);
	private:
		GLuint name_;
	};

}