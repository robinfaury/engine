#include "gpu.h"

class Ressources {
public:
	static GLuint texture;

	static void loadTexture() {
		glGenTextures(1, &texture);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		const GLfloat data[] = { 1.f, 1.f, 0.f, 1.f,
			1.f, 0.f, 0.f, 1.f,
			0.f, 0.f, 1.f, 1.f,
			1.f, 0.f, 1.f, 1.f };
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_FLOAT, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};