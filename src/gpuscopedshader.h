#include "gpu.h"

class gpuScopedShader {
public:
	gpuScopedShader();
	gpuScopedShader(const char* vs, const char* fs);

	void create(const char* vs, const char* fs);

	~gpuScopedShader();
private:
	GLuint compileShader(const char* shader, GLuint shaderType);

private:
	GLuint programName_;
#ifdef _DEBUG
	GLchar logVs_[512];
	GLchar logFs_[512];
	GLchar logProgram_[512];
#endif
};
