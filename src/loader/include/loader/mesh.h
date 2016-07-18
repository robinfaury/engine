#pragma once

#include "SubMesh.h"

namespace Loader {

	class Mesh
	{
	public:
		Mesh() = delete;
		Mesh(const char * path);
		~Mesh();

		void draw();

		float normelize();

	private:
		std::vector<SubMesh> subMesh_;
	};

}