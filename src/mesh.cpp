#include "Mesh.h"

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

Mesh::Mesh(const char * path) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_PreTransformVertices);

	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		std::cout<<"ERROR: Assimp can't import "<<path<<std::endl;
		return;
	}
	unsigned int nbVertex = 0;
	unsigned int nbTriangle = 0;
	for (unsigned int idMesh=0; idMesh< scene->mNumMeshes; ++idMesh) {
		aiMesh* mesh = scene->mMeshes[idMesh];
		aiString name;
		scene->mMaterials[idMesh]->Get(AI_MATKEY_NAME,name);
		subMesh_.push_back(SubMesh(name.C_Str()));
		nbVertex += mesh->mNumVertices;
		for (GLuint i = 0; i < mesh->mNumVertices; ++i) {
			VertexDesc vertex;
			vertex.position.x = mesh->mVertices[i].x;
			vertex.position.y = mesh->mVertices[i].y;
			vertex.position.z = mesh->mVertices[i].z;

			vertex.normal.x = mesh->mNormals[i].x;
			vertex.normal.y = mesh->mNormals[i].y;
			vertex.normal.z = mesh->mNormals[i].z;

			vertex.uv.x = mesh->mTextureCoords[0][i].x;
			vertex.uv.y = mesh->mTextureCoords[0][i].y;

			subMesh_[idMesh].addVertex(vertex);
		}

		nbTriangle += mesh->mNumFaces;
		for (GLuint i = 0; i < mesh->mNumFaces; ++i) {
			for (GLuint j = 0; j < mesh->mFaces[i].mNumIndices; ++j) {
				subMesh_[idMesh].addIndice(mesh->mFaces[i].mIndices[j]);
			}
		}
	}

	std::cout<<"Mesh with "<<nbVertex<<" vertices and "<<nbTriangle<<" triangles."<<std::endl;

	float scaleRatio = normelize();

	for (unsigned int idMesh=0; idMesh< scene->mNumMeshes; ++idMesh) {
		subMesh_[idMesh].scale(scaleRatio * 0.2f);
		subMesh_[idMesh].sendOnGraphicCard();
	}
}

Mesh::~Mesh() {}

void Mesh::draw() {
	for (std::vector<SubMesh>::iterator subMesh = subMesh_.begin(); subMesh != subMesh_.end(); ++subMesh) {
		subMesh->draw();
	}
}

float Mesh::normelize() {
	std::vector<float> min, max;
	for (int i=0; i< subMesh_.size(); ++i) {
		min.push_back(subMesh_[i].getMin());
		max.push_back(subMesh_[i].getMax());
	}
	std::sort(min.begin(), min.end());
	std::sort(max.begin(), max.end());

	return max[max.size()-1] - min[0];
}

const SubMesh& Mesh::getSubMeshConst(unsigned int id) const {
	assert(subMesh_.size() > 0);
	if (id < subMesh_.size()) {
		return subMesh_[id];
	}
	return subMesh_[0];
}

SubMesh& Mesh::getSubMesh(unsigned int id) {
	assert(subMesh_.size() > 0);
	if (id < subMesh_.size()) {
		return subMesh_[id];
	}
	return subMesh_[0];
}

const unsigned int Mesh::nbSubMesh() const {
	return static_cast<unsigned int>(subMesh_.size());
}
