#include "gpu.h"

static GLuint compileShader(std::string shaderCode, GLuint shaderType) {
	const char* shaderSTR = shaderCode.c_str();
	GLuint shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &shaderSTR, NULL);
	glCompileShader(shaderID);

	GLint success;
	GLchar log[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shaderID, 512, NULL, log);
		if (shaderType == GL_VERTEX_SHADER) {
			std::cout << "VERTEX SHADER COMPILATION FAIL: \n" << log << std::endl;
		}
		else if (shaderType == GL_FRAGMENT_SHADER) {
			std::cout << "FRAGMENT SHADER COMPILATION FAIL: \n" << log << std::endl;
		}
	}

	return shaderID;
}

static GLuint compileTwoShaderAndLinkProgram(std::string shaderCodeOne, GLuint shaderTypeOne, std::string shaderCodeTwo, GLuint shaderTypeTwo) {
	GLuint vertexID = compileShader(shaderCodeOne, shaderTypeOne);
	GLuint fragmentID = compileShader(shaderCodeTwo, shaderTypeTwo);

	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	glLinkProgram(programID);

	GLint success;
	GLchar log[512];
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(programID, 512, NULL, log);
		std::cout << "LINK PROGRAM FAIL: \n" << log << std::endl;
	}

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);

	return programID;
}