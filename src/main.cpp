
#include "ressources.h"

const char *vsPassThru =
"#version 150\n"
"const vec2 positionGen[3] = vec2[3](vec2(0.0, 0.0), vec2(1.0, 0.0), vec2(0.0, 1.0));"
"out vec2 texCoord;\n"
"void main()\n"
"{\n"
"	 texCoord = positionGen[gl_VertexID];\n"
"	 gl_Position = vec4(2.0*positionGen[gl_VertexID]-1.0, 0.0, 1.0);\n"
"}\n";

const char *vsCube =
"#version 150\n"
"const vec3 positionGen[36] = vec3[36]("
"vec3(-1.0f,-1.0f,-1.0f),"
"vec3(- 1.0f, -1.0f, 1.0f),"
"vec3(-1.0f, 1.0f, 1.0f),"
"vec3(1.0f, 1.0f, -1.0f),"
"vec3(-1.0f, -1.0f, -1.0f),"
"vec3(-1.0f, 1.0f, -1.0f),"
"vec3(1.0f, -1.0f, 1.0f),"
"vec3(-1.0f, -1.0f, -1.0f),"
"vec3(1.0f, -1.0f, -1.0f),"
"vec3(1.0f, 1.0f, -1.0f),"
"vec3(1.0f, -1.0f, -1.0f),"
"vec3(-1.0f, -1.0f, -1.0f),"
"vec3(-1.0f, -1.0f, -1.0f),"
"vec3(-1.0f, 1.0f, 1.0f),"
"vec3(-1.0f, 1.0f, -1.0f),"
"vec3(1.0f, -1.0f, 1.0f),"
"vec3(-1.0f, -1.0f, 1.0f),"
"vec3(-1.0f, -1.0f, -1.0f),"
"vec3(-1.0f, 1.0f, 1.0f),"
"vec3(-1.0f, -1.0f, 1.0f),"
"vec3(1.0f, -1.0f, 1.0f),"
"vec3(1.0f, 1.0f, 1.0f),"
"vec3(1.0f, -1.0f, -1.0f),"
"vec3(1.0f, 1.0f, -1.0f),"
"vec3(1.0f, -1.0f, -1.0f),"
"vec3(1.0f, 1.0f, 1.0f),"
"vec3(1.0f, -1.0f, 1.0f),"
"vec3(1.0f, 1.0f, 1.0f),"
"vec3(1.0f, 1.0f, -1.0f),"
"vec3(-1.0f, 1.0f, -1.0f),"
"vec3(1.0f, 1.0f, 1.0f),"
"vec3(-1.0f, 1.0f, -1.0f),"
"vec3(-1.0f, 1.0f, 1.0f),"
"vec3(1.0f, 1.0f, 1.0f),"
"vec3(-1.0f, 1.0f, 1.0f),"
"vec3(1.0f, -1.0f, 1.0f)); "
"const vec2 uvGen[36] = vec2[36]("
"vec2(0.000059f, 1.0f - 0.000004f),"
"vec2(0.000103f, 1.0f - 0.336048f),"
"vec2(0.335973f, 1.0f - 0.335903f),"
"vec2(1.000023f, 1.0f - 0.000013f),"
"vec2(0.667979f, 1.0f - 0.335851f),"
"vec2(0.999958f, 1.0f - 0.336064f),"
"vec2(0.667979f, 1.0f - 0.335851f),"
"vec2(0.336024f, 1.0f - 0.671877f),"
"vec2(0.667969f, 1.0f - 0.671889f),"
"vec2(1.000023f, 1.0f - 0.000013f),"
"vec2(0.668104f, 1.0f - 0.000013f),"
"vec2(0.667979f, 1.0f - 0.335851f),"
"vec2(0.000059f, 1.0f - 0.000004f),"
"vec2(0.335973f, 1.0f - 0.335903f),"
"vec2(0.336098f, 1.0f - 0.000071f),"
"vec2(0.667979f, 1.0f - 0.335851f),"
"vec2(0.335973f, 1.0f - 0.335903f),"
"vec2(0.336024f, 1.0f - 0.671877f),"
"vec2(1.000004f, 1.0f - 0.671847f),"
"vec2(0.999958f, 1.0f - 0.336064f),"
"vec2(0.667979f, 1.0f - 0.335851f),"
"vec2(0.668104f, 1.0f - 0.000013f),"
"vec2(0.335973f, 1.0f - 0.335903f),"
"vec2(0.667979f, 1.0f - 0.335851f),"
"vec2(0.335973f, 1.0f - 0.335903f),"
"vec2(0.668104f, 1.0f - 0.000013f),"
"vec2(0.336098f, 1.0f - 0.000071f),"
"vec2(0.000103f, 1.0f - 0.336048f),"
"vec2(0.000004f, 1.0f - 0.671870f),"
"vec2(0.336024f, 1.0f - 0.671877f),"
"vec2(0.000103f, 1.0f - 0.336048f),"
"vec2(0.336024f, 1.0f - 0.671877f),"
"vec2(0.335973f, 1.0f - 0.335903f),"
"vec2(0.667969f, 1.0f - 0.671889f),"
"vec2(1.000004f, 1.0f - 0.671847f),"
"vec2(0.667979f, 1.0f - 0.335851f));"
"uniform mat4 MVP;"
"out vec2 texCoord;\n"
"void main()\n"
"{\n"
"	texCoord = uvGen[gl_VertexID];\n"
"	gl_Position = MVP * vec4(positionGen[gl_VertexID], 1.0);\n"
"}\n";

const char *fsCube =
"#version 150\n"
"in vec2 texCoord;"
"out vec4 outColor;\n"
"void main()\n"
"{\n"
"  outColor = vec4(texCoord, 0.0, 0.5);\n"
"}\n";

const char *fsPassThru =
"#version 150\n"
"in vec2 texCoord;\n"
"uniform sampler2D myTextureSampler;\n"
"out vec4 outColor;\n"
"void main()\n"
"{\n"
"  outColor = texture(myTextureSampler, texCoord);\n"
"}\n";

const char *gray =
"#version 150\n"
"in vec2 texCoord;\n"
"uniform sampler2D myTextureSampler;\n"
"out vec4 outColor;\n"
"void main()\n"
"{\n"
"  vec4 color = texture(myTextureSampler, texCoord);\n"
"  float grey = (color.x + color.y + color.z)/3.0;\n"
"  outColor = vec4(grey, grey, grey, color.w);\n"
"}\n";

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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window;
	window = glfwCreateWindow(512, 512, "testGL", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.2 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return;

	}

	glfwMakeContextCurrent(window);
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}
	printf("GLEW: %d\n", glGetError());



	GLint majorVersion;
	glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);

	glDisable(GL_STENCIL_TEST);
	glStencilFunc(GL_ALWAYS, 0, 0xff);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

	//======================================================
	Ressources::loadTexture();

	glfwMakeContextCurrent(window);
	//======================================================
	glViewport(0, 0, 512, 512);
	GLuint p = compileTwoShaderAndLinkProgram(vsPassThru, GL_VERTEX_SHADER, fsPassThru, GL_FRAGMENT_SHADER);
	GLuint postProcess = compileTwoShaderAndLinkProgram(vsPassThru, GL_VERTEX_SHADER, gray, GL_FRAGMENT_SHADER);
	GLuint cube = compileTwoShaderAndLinkProgram(vsCube, GL_VERTEX_SHADER, fsCube, GL_FRAGMENT_SHADER);
	GLuint vao;
	glGenVertexArrays(1, &vao);

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

	glBindVertexArray(vao);
	while (!glfwWindowShouldClose(window))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		glClearColor(1.0, 0.0, 1.0, 0.0);
		glClearDepth(1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(p);
		glBindTexture(GL_TEXTURE_2D, Ressources::texture);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindTexture(GL_TEXTURE_2D, 0);
		glUseProgram(0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glBindTexture(GL_TEXTURE_2D, outTexture);
		glUseProgram(postProcess);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(0);
		glBindTexture(GL_TEXTURE_2D, 0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		printf("%d", glGetError());
		glDisable(GL_CULL_FACE);
		printf("%d", glGetError());
		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 1.f, 0.1f, 100.0f);
		glm::mat4 View = glm::lookAt(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		glm::mat4 Model = glm::mat4(1.0f);
		glm::mat4 mvp = Projection * View * Model;
		glUseProgram(cube);
		
		glUniformMatrix4fv(glGetUniformLocation(cube, "MVP"), 1, GL_FALSE, &mvp[0][0]);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glUseProgram(0);
		

		glfwSwapBuffers(window);
	}
	glBindVertexArray(0);
}
