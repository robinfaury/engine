#pragma once

#include "gpubinder.h"
#include <loader/image.h>

namespace Gpu {

	class GpuTexture {
	public:
		/*********BINDER***********/
		class ScopedGpuTextureBinder : public GpuBinder {
		public:
			ScopedGpuTextureBinder() = delete;
			ScopedGpuTextureBinder(const GpuTexture& texture, GLuint activeTexture = 0) 
				: texture_(texture), activeTexture_(activeTexture) 
				{ bind(); }
			~ScopedGpuTextureBinder() { release(); }
			void bind() { 
				glActiveTexture(GL_TEXTURE0 + activeTexture_); OGLERROR;
				glBindTexture(GL_TEXTURE_2D, texture_.name_); OGLERROR; }
			void release() { 
				glActiveTexture(GL_TEXTURE0 + activeTexture_); OGLERROR;
				glBindTexture(GL_TEXTURE_2D, 0); OGLERROR; }
		private:
			const GpuTexture& texture_;
			GLuint activeTexture_;
		};


		/************IMPL***********/
		GpuTexture();
		GpuTexture(const Loader::Image& image);
	private:
		GLuint name_;
	};

}