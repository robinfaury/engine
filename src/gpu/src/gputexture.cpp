#include <gpu/gputexture.h>

namespace Gpu {

	GpuTexture::GpuTexture() : name_(0) {}

	GpuTexture::GpuTexture(const Loader::Image& image) {
		glGenTextures(1, &name_);
		OGLERROR;
		glBindTexture(GL_TEXTURE_2D, name_);
		OGLERROR;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		OGLERROR;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		OGLERROR;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		OGLERROR;
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		OGLERROR;
		GLint internalformat = 0;
		GLenum format = 0;
		switch(image.bpp_) {
		case 8:
			internalformat = GL_R; format = GL_R; break;
		case 16:
			internalformat = GL_RG; format = GL_RG; break;
		case 24:
			internalformat = GL_RGB; format = GL_BGR; break;
		case 32:
			internalformat = GL_RGBA; format = GL_BGRA; break;
		default:
			assert(false);
		}
		glTexImage2D(GL_TEXTURE_2D, 0, internalformat, 512, 512, 0, format, GL_UNSIGNED_BYTE, image.bits_);
		OGLERROR;
		glGenerateMipmap(GL_TEXTURE_2D);
		OGLERROR;
	}

}