#pragma once

#include "gpubinder.h"

namespace Gpu {

	class GpuProgram {
	public:
		/*********BINDER***********/
		class ScopedGpuProgramBinder : public GpuBinder {
		public:
			ScopedGpuProgramBinder() = delete;
			ScopedGpuProgramBinder(GpuProgram* program) : program_(program) { bind(); }
			~ScopedGpuProgramBinder() { release(); }
			void bind() {glUseProgram(program_->name_); OGLERROR;}
			void release() {glUseProgram(0); OGLERROR;}

			//void operator[] (const char* name) {}
			//void operator= (float data);

		private:
			GpuProgram* program_;
		};


		/************IMPL***********/
		GpuProgram();

		GpuProgram(const char * vs, const char * fs);

		void create(const char * vs, const char * fs);

		GLuint compileShader(const char * shader, GLuint shaderType);

		~GpuProgram();

	public:
		GLuint name_;
#ifdef _DEBUG
		GLint success_;
		GLchar logVs_[512];
		GLchar logFs_[512];
		GLchar logProgram_[512];
#endif
	};

}