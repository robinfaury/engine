#include "SubMesh.h"

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

SubMesh::SubMesh(std::string name) 
	: drawingMode_(GL_TRIANGLES)
	, VAO_(0)
	, VBO_(0)
	, EBO_(0)
	, visible_(true)
	, name_(name) {
	
}

SubMesh::~SubMesh() {}

const std::vector<VertexDesc>& SubMesh::getVertices() const {
	return vertices_;
}

const std::vector<unsigned int>& SubMesh::getIndices() const {
	return indices_;
}

GLuint SubMesh::getVAO() const {
	return VAO_;
}

GLuint SubMesh::getEBO() const {
	return EBO_;
}

GLuint SubMesh::getDrawingMode() const {
	return drawingMode_;
}

const bool SubMesh::isVisible() const {
	return visible_;
}

void SubMesh::setVisible(bool visibility) {
	visible_ = visibility;
}

std::string SubMesh::getName() const {
	return name_;
}

void SubMesh::addVertex(VertexDesc& vertex) {
	vertices_.push_back(vertex);
}

void SubMesh::addIndice(GLuint indice) {
	indices_.push_back(indice);
}

float SubMesh::getMin() {
	float minX = FLT_MAX, minY = FLT_MAX, minZ = FLT_MAX;

	for (std::vector<VertexDesc>::iterator vertex = vertices_.begin(); vertex != vertices_.end(); ++vertex)
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

	for (std::vector<VertexDesc>::iterator vertex = vertices_.begin(); vertex != vertices_.end(); ++vertex)
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
	for (std::vector<VertexDesc>::iterator v = vertices_.begin(); v != vertices_.end(); ++v)
	{
		(*v).position.x = (*v).position.x / scaleRatio;
		(*v).position.y = (*v).position.y / scaleRatio;
		(*v).position.z = (*v).position.z / scaleRatio;
	}
}

void SubMesh::sendOnGraphicCard()
{
	glGenVertexArrays(1, &VAO_);
	glGenBuffers(1, &VBO_);
	glGenBuffers(1, &EBO_);

	glBindVertexArray(VAO_);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_);
		glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(VertexDesc), &vertices_[0], GL_STATIC_DRAW);
		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(GLuint), &indices_[0], GL_STATIC_DRAW);
		
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)(sizeof(glm::vec3)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)(2*sizeof(glm::vec3)));
	glBindVertexArray(0);
}

void SubMesh::draw() {
	glBindVertexArray(VAO_);
	glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT, (void*)0);
	glBindVertexArray(0);
}