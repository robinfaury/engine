#include "gpuscopedshader.h"

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
	glGetProgramiv(programName_, GL_LINK_STATUS, &success_);
	if (!success_) {
		glGetProgramInfoLog(programName_, 512, nullptr, logProgram_);
		printf("%s", logProgram_);
	}
#endif

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);

	glUseProgram(programName_);
}

void gpuScopedShader::bind() {
	glUseProgram(programName_);
}

void gpuScopedShader::release() {
	glUseProgram(0);
}

GLuint gpuScopedShader::compileShader(const char* shader, GLuint shaderType) {
	GLuint shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &shader, nullptr);
	glCompileShader(shaderID);

#ifdef _DEBUG
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success_);
	if (!success_) {
		if (shaderType == GL_VERTEX_SHADER) {
			glGetShaderInfoLog(shaderID, 512, nullptr, logVs_);
			printf("%s", logVs_);
		}
		else if (shaderType == GL_FRAGMENT_SHADER) {
			glGetShaderInfoLog(shaderID, 512, nullptr, logFs_);
			printf("%s", logFs_);
		}
	}
#endif

	return shaderID;
}

bool gpuScopedShader::isLink() {
	return success_;
}

gpuScopedShader::~gpuScopedShader() {
	glUseProgram(0);
	glDeleteProgram(programName_);
}
