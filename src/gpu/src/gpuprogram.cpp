#include <gpu/gpuprogram.h>

namespace Gpu {

	GpuProgram::GpuProgram()
		: name_(0) {

	}

	GpuProgram::GpuProgram(const char* vs, const char* fs) {
		create(vs, fs);
	}

	void GpuProgram::create(const char* vs, const char* fs) {
		GLuint vertexID = compileShader(vs, GL_VERTEX_SHADER);
		GLuint fragmentID = compileShader(fs, GL_FRAGMENT_SHADER);

		name_ = glCreateProgram();
		OGLERROR;
		glAttachShader(name_, vertexID);
		OGLERROR;
		glAttachShader(name_, fragmentID);
		OGLERROR;
		glLinkProgram(name_);
		OGLERROR;

#ifdef _DEBUG
		glGetProgramiv(name_, GL_LINK_STATUS, &success_);
		OGLERROR;
		if (!success_) {
			glGetProgramInfoLog(name_, 512, nullptr, logProgram_);
			OGLERROR;
			printf("%s", logProgram_);
	}
#endif

		glDeleteShader(vertexID);
		OGLERROR;
		glDeleteShader(fragmentID);
		OGLERROR;
}

	GLuint GpuProgram::compileShader(const char* shader, GLuint shaderType) {
		GLuint shaderID = glCreateShader(shaderType);
		OGLERROR;
		glShaderSource(shaderID, 1, &shader, nullptr);
		OGLERROR;
		glCompileShader(shaderID);
		OGLERROR;

#ifdef _DEBUG
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success_);
		OGLERROR;
		if (!success_) {
			if (shaderType == GL_VERTEX_SHADER) {
				glGetShaderInfoLog(shaderID, 512, nullptr, logVs_);
				OGLERROR;
				printf("%s", logVs_);
			}
			else if (shaderType == GL_FRAGMENT_SHADER) {
				glGetShaderInfoLog(shaderID, 512, nullptr, logFs_);
				OGLERROR;
				printf("%s", logFs_);
			}
		}
#endif

		return shaderID;
	}

	GpuProgram::~GpuProgram()
	{
		assert(name_ != 0);
		glDeleteProgram(name_);
		OGLERROR;
	}
}
