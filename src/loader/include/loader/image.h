#pragma once

#include <FreeImage.h>

namespace Loader {

	class Image {
	public:
		Image();
		Image(const char* path);
		~Image();

		bool open(const char* path);

		FREE_IMAGE_FORMAT format();
		unsigned int width();
		unsigned int height();

		BYTE* bits();

	private:
		FREE_IMAGE_FORMAT format_;
		unsigned int width_;
		unsigned int height_;

		BYTE* bits_;

		FIBITMAP* imagePtr_;

	};

}