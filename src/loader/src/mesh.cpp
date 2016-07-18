#include <loader/mesh.h>

namespace Loader {

	////////////////////////////////////////////////////////////////////////////////////////
	//                                                                                    //
	////////////////////////////////////////////////////////////////////////////////////////

	Mesh::Mesh(const char * path) {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_PreTransformVertices);

		if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
			std::cout << "ERROR: Assimp can't import " << path << std::endl;
			return;
		}
		unsigned int nbVertex = 0;
		unsigned int nbTriangle = 0;
		for (unsigned int idMesh = 0; idMesh < scene->mNumMeshes; ++idMesh) {
			aiMesh* mesh = scene->mMeshes[idMesh];
			aiString name;
			scene->mMaterials[idMesh]->Get(AI_MATKEY_NAME, name);
			subMesh_.push_back(SubMesh());
			nbVertex += mesh->mNumVertices;
			std::vector<Gpu::GpuGeometry::VertexDesc>& vertices = subMesh_[idMesh].getVertices();
			vertices.reserve(mesh->mNumVertices);
			for (GLuint i = 0; i < mesh->mNumVertices; ++i) {
				Gpu::GpuGeometry::VertexDesc vertex;
				vertex.position.x = mesh->mVertices[i].x;
				vertex.position.y = mesh->mVertices[i].y;
				vertex.position.z = mesh->mVertices[i].z;

				vertex.normal.x = mesh->mNormals[i].x;
				vertex.normal.y = mesh->mNormals[i].y;
				vertex.normal.z = mesh->mNormals[i].z;

				vertex.uv.x = mesh->mTextureCoords[0][i].x;
				vertex.uv.y = mesh->mTextureCoords[0][i].y;

				vertices.push_back(vertex);
			}

			nbTriangle += mesh->mNumFaces;
			std::vector<GLuint>& indices = subMesh_[idMesh].getIndices();
			indices.reserve(mesh->mNumFaces);
			for (GLuint i = 0; i < mesh->mNumFaces; ++i) {
				for (GLuint j = 0; j < mesh->mFaces[i].mNumIndices; ++j) {
					indices.push_back(mesh->mFaces[i].mIndices[j]);
				}
			}
		}

		std::cout << "Mesh with " << nbVertex << " vertices and " << nbTriangle << " triangles." << std::endl;

		float scaleRatio = normelize();

		for (unsigned int idMesh = 0; idMesh < scene->mNumMeshes; ++idMesh) {
			subMesh_[idMesh].scale(scaleRatio * 0.2f);
			subMesh_[idMesh].commit();
		}
	}

	Mesh::~Mesh() {}

	void Mesh::draw()
	{
		for (std::vector<SubMesh>::iterator subMesh = subMesh_.begin(); subMesh != subMesh_.end(); ++subMesh) {
			const Gpu::GpuGeometry& geo = subMesh->getGpuGeometry();
			Gpu::GpuGeometry::ScopedGpuGeometryBinder binder(&geo);
			geo.draw();
		}
	}

	float Mesh::normelize() {
		std::vector<float> min, max;
		for (int i = 0; i < subMesh_.size(); ++i) {
			min.push_back(subMesh_[i].getMin());
			max.push_back(subMesh_[i].getMax());
		}
		std::sort(min.begin(), min.end());
		std::sort(max.begin(), max.end());

		return max[max.size() - 1] - min[0];
	}

}