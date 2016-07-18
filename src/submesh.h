#pragma once

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <limits.h>

struct VertexDesc
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 uv;
};

class SubMesh {
public:
	SubMesh(std::string name);
	~SubMesh();

	const std::vector<VertexDesc>& getVertices() const;
	const std::vector<GLuint>& getIndices() const;

	GLuint getVAO() const;
	GLuint getEBO() const;
	GLuint getDrawingMode() const;
	const bool isVisible() const;
	std::string getName() const;
	void setVisible(bool visibility);

	void addVertex(VertexDesc& vertex);
	void addIndice(GLuint indice);
	float getMin();
	float getMax();
	void scale(float scaleRatio);

	/*!
		\brief Generate the VAO, VBO and EBO of the mesh.
	*/
	void sendOnGraphicCard();

	void draw();
	
private:
	std::vector<VertexDesc> vertices_;
	std::vector<GLuint> indices_;

	GLuint VAO_;
	GLuint VBO_;
	GLuint EBO_;
	GLuint drawingMode_;

	bool visible_;

	std::string name_;
};
