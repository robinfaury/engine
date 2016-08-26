#pragma once

#include "gpubinder.h"

namespace Gpu {

	class GpuProgram {
	public:
		/*********BINDER***********/
		class ScopedGpuProgramBinder : public GpuBinder {
		public:
			ScopedGpuProgramBinder() = delete;
			ScopedGpuProgramBinder(const GpuProgram& program) : program_(program) { bind(); }
			~ScopedGpuProgramBinder() { release(); }
			void bind() {glUseProgram(program_.name_); OGLERROR;}
			void release() {glUseProgram(0); OGLERROR;}

			class UniformBinding {
			public:
				UniformBinding(GLint location) : location_(location) {}
				void operator= (float data) { glUniform1f(location_, data); OGLERROR; }
				void operator= (float* data) { glUniformMatrix4fv(location_, 1, GL_FALSE, data); OGLERROR; }
			private:
				GLint location_;
			};

			UniformBinding operator[] (const char* name) {
				return UniformBinding(glGetUniformLocation(program_.name_, name));
			}

		private:
			const GpuProgram& program_;
		};


		/************IMPL***********/
		GpuProgram();

		GpuProgram(const char * vs, const char * fs);

		void create(const char * vs, const char * fs);

		GLuint compileShader(const char * shader, GLuint shaderType);

		~GpuProgram();

	private:
		GLuint name_;
#ifdef _DEBUG
		GLint success_;
		GLchar logVs_[512];
		GLchar logFs_[512];
		GLchar logProgram_[512];
#endif
	};

}