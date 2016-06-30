#include "gpushader.h"

gpuScopedShader::gpuScopedShader()
	: programName_(0) {

}

gpuScopedShader::gpuScopedShader(const char* vs, const char* fs) {
	create(vs, fs);
}

void gpuScopedShader::create(const char* vs, const char* fs) {
	GLuint vertexID = compileShader(vs, GL_VERTEX_SHADER);
	GLuint fragmentID = compileShader(fs, GL_FRAGMENT_SHADER);

	GLuint programName_ = glCreateProgram();
	glAttachShader(programName_, vertexID);
	glAttachShader(programName_, fragmentID);
	glLinkProgram(programName_);

#ifdef _DEBUG
	GLint success;
	glGetProgramiv(programName_, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(programName_, 512, nullptr, logProgram_);
	}
#endif

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);

	glUseProgram(programName_);
}

GLuint gpuScopedShader::compileShader(const char* shader, GLuint shaderType) {
	GLuint shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &shader, nullptr);
	glCompileShader(shaderID);

#ifdef _DEBUG
	GLint success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success) {
		if (shaderType == GL_VERTEX_SHADER) {
			glGetShaderInfoLog(shaderID, 512, nullptr, logVs_);
		}
		else if (shaderType == GL_FRAGMENT_SHADER) {
			glGetShaderInfoLog(shaderID, 512, nullptr, logFs_);
		}
	}
#endif
}

gpuScopedShader::~gpuScopedShader() {
	glUseProgram(0);
	glDeleteProgram(programName_);
}
