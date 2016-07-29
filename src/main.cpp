#include <gpu/gpuprogram.h>
#include <gpu/gpugeometry.h>
#include <loader/mesh.h>
#include <loader/image.h>
#include <iostream>
#include <GLFW/glfw3.h>

const char *vsBillboard =
"#version 330 core\n"
"const vec2 positionGen[3] = vec2[3](vec2(0.0, 0.0), vec2(1.0, 0.0), vec2(0.0, 1.0));"
"out vec2 texCoord;\n"
"void main()\n"
"{\n"
"	texCoord = positionGen[gl_VertexID];\n"
"	gl_Position = vec4(2.0*positionGen[gl_VertexID]-1.0, 0.0, 1.0);\n"
"}\n";

const char *vsBakerPosition =
"#version 330 core\n"
"layout (location = 0) in vec3 in_position;"
"layout (location = 1) in vec3 in_normal;"
"layout (location = 2) in vec2 in_uv;"
"out vec3 position;\n"
"void main()\n"
"{\n"
"	position = in_normal;\n"
"	gl_Position = vec4(2.0*in_uv-1.0, 0.0, 1.0);\n"
"}\n";

const char *fsBakerPosition =
"#version 330 core\n"
"in vec3 position;\n"
"out vec4 oColor0;\n"
"void main()\n"
"{\n"
"	oColor0 = vec4((position+1.0)*0.5, 1.0);\n"
"}\n";


void APIENTRY openglCallbackFunction(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam) {}

void main() {
	if (!glfwInit())
	{
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window;
	window = glfwCreateWindow(512, 512, "engine", NULL, NULL);
	if (window == NULL) {
		printf("Failed to open GLFW window. If you have an Intel GPU, they are not 3.2 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}
	printf("GLEW ERROR: %d\n", glGetError());

	GLuint outTexture;
	glGenTextures(1, &outTexture);
	glBindTexture(GL_TEXTURE_2D, outTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	GLuint fbo;
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, outTexture, 0);
	GLenum status;
	status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	{
		Gpu::GpuProgram baker(vsBakerPosition, fsBakerPosition);
		Loader::Mesh cube("../res/cube.fbx");
		Loader::Image img;
		img.open("../res/image.png");

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.1f, 0.0f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Gpu::GpuProgram::ScopedGpuProgramBinder binder(&baker);
			cube.draw();

			glfwPollEvents();
			glfwSwapBuffers(window);
		}
		glBindVertexArray(0);

	}

	glfwTerminate();
}
