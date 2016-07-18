#pragma once

#include <gpu/gpugeometry.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <limits.h>

namespace Loader {

	class SubMesh {
	public:
		SubMesh();
		~SubMesh();

		std::vector<Gpu::GpuGeometry::VertexDesc>& getVertices();
		std::vector<GLuint>& getIndices();

		void addVertex(Gpu::GpuGeometry::VertexDesc& vertex);
		void addIndice(unsigned int indice);
		float getMin();
		float getMax();
		void scale(float scaleRatio);

		void commit();

		const Gpu::GpuGeometry& getGpuGeometry();

	private:
		std::vector<Gpu::GpuGeometry::VertexDesc> vertices_;
		std::vector<GLuint> indices_;

		Gpu::GpuGeometry gpuGeo_;
	};

}