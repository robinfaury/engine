#pragma once

#include <FreeImage.h>

namespace Loader {

	class Image {
	public:
		BYTE* bits_;
		FIBITMAP* dib_;
		FREE_IMAGE_FORMAT fif_;
		unsigned int width_;
		unsigned int height_;
		unsigned int bpp_;

		Image(char* path) {
			fif_ = FIF_UNKNOWN;
			fif_ = FreeImage_GetFileType(path, 0);
			if (fif_ == FIF_UNKNOWN) {
				fif_ = FreeImage_GetFIFFromFilename(path);
			}
			if ((fif_ != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif_)) {
				dib_ = FreeImage_Load(fif_, path);
				width_ = FreeImage_GetWidth(dib_);
				height_ = FreeImage_GetHeight(dib_);
				bits_ = FreeImage_GetBits(dib_);
				bpp_ = FreeImage_GetBPP(dib_);
			}
		}
	};

}