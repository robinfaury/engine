#include "../include/loader/image.h"

namespace Loader {

	Image::Image()
		: format_(FIF_UNKNOWN)
		, width_(0)
		, height_(0)
		, bits_(0)
		, imagePtr_(0)
	{}

	Image::Image(const char* path)
		: format_(FIF_UNKNOWN)
		, width_(0)
		, height_(0)
		, bits_(0)
		, imagePtr_(0)
	{
		open(path);
	}

	Image::~Image()
	{
		FreeImage_Unload(imagePtr_);
	}

	bool Image::open(const char* path)
	{
		format_ = FreeImage_GetFileType(path, 0);
		if (format_ == FIF_UNKNOWN) {
			format_ = FreeImage_GetFIFFromFilename(path);
		}
		if (format_ == FIF_UNKNOWN) {
			return false;
		}

		if (FreeImage_FIFSupportsReading(format_))
			imagePtr_ = FreeImage_Load(format_, path);
		if (!imagePtr_)
			return false;

		bits_ = FreeImage_GetBits(imagePtr_);
		width_ = FreeImage_GetWidth(imagePtr_);
		height_ = FreeImage_GetHeight(imagePtr_);
		if ((bits_ == 0) || (width_ == 0) || (height_ == 0))
			return false;
		return true;
	}

	FREE_IMAGE_FORMAT Image::format()
	{
		return format_;
	}

	unsigned int Image::width()
	{
		return width_;
	}

	unsigned int Image::height()
	{
		return height_;
	}

	BYTE* Image::bits()
	{
		return bits_;
	}

}