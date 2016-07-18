#pragma once

/*!
 * \file .h
 * \version 0.1
*/

#include "SubMesh.h"

/*!
	\class 
	\brief 
*/
class Mesh
{
public:
	Mesh() = delete;
	Mesh(const char * path);
	~Mesh();

	float normelize();

	void draw();

	const SubMesh& getSubMeshConst(unsigned int id) const;
	SubMesh& getSubMesh(unsigned int id);
	const unsigned int nbSubMesh() const;

private:
	std::vector<SubMesh> subMesh_;
};
