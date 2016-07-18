#include <loader/submesh.h>

namespace Loader {

	////////////////////////////////////////////////////////////////////////////////////////
	//                                                                                    //
	////////////////////////////////////////////////////////////////////////////////////////

	SubMesh::SubMesh() {}

	SubMesh::~SubMesh() {}

	std::vector<Gpu::GpuGeometry::VertexDesc>& SubMesh::getVertices() {
		return vertices_;
	}

	std::vector<unsigned int>& SubMesh::getIndices() {
		return indices_;
	}

	void SubMesh::addVertex(Gpu::GpuGeometry::VertexDesc& vertex) {
		vertices_.push_back(vertex);
	}

	void SubMesh::addIndice(unsigned int indice) {
		indices_.push_back(indice);
	}

	float SubMesh::getMin() {
		float minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;

		for (std::vector<Gpu::GpuGeometry::VertexDesc>::iterator vertex = vertices_.begin(); vertex != vertices_.end(); ++vertex)
		{
			if (minX > (*vertex).position.x)
				minX = (*vertex).position.x;
			if (minY > (*vertex).position.y)
				minY = (*vertex).position.y;
			if (minZ > (*vertex).position.z)
				minZ = (*vertex).position.z;
		}
		float min = minX;
		if (min > minY)
			min = minY;
		if (min > minZ)
			min = minZ;

		return min;
	}

	float SubMesh::getMax() {
		float maxX = 0.f, maxY = 0.f, maxZ = 0.f;

		for (std::vector<Gpu::GpuGeometry::VertexDesc>::iterator vertex = vertices_.begin(); vertex != vertices_.end(); ++vertex)
		{
			if (maxX < (*vertex).position.x)
				maxX = (*vertex).position.x;
			if (maxY < (*vertex).position.y)
				maxY = (*vertex).position.y;
			if (maxZ < (*vertex).position.z)
				maxZ = (*vertex).position.z;
		}

		float max = maxX;
		if (max < maxY)
			max = maxY;
		if (max < maxZ)
			max = maxZ;

		return max;
	}

	void SubMesh::scale(float scaleRatio) {
		for (std::vector<Gpu::GpuGeometry::VertexDesc>::iterator v = vertices_.begin(); v != vertices_.end(); ++v)
		{
			(*v).position.x = (*v).position.x / scaleRatio;
			(*v).position.y = (*v).position.y / scaleRatio;
			(*v).position.z = (*v).position.z / scaleRatio;
		}
	}

	void SubMesh::commit()
	{
		gpuGeo_.create(vertices_, indices_);
	}

	const Gpu::GpuGeometry & SubMesh::getGpuGeometry()
	{
		return gpuGeo_;
	}

}