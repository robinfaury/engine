#include "..\include\gpu\gpugeometry.h"

namespace Gpu {

	GpuGeometry::GpuGeometry()
	{
	}

	GpuGeometry::GpuGeometry(const std::vector<VertexDesc>& vertices, const std::vector<GLuint>& indices)
	{
		create(vertices, indices);
	}

	void GpuGeometry::create(const std::vector<VertexDesc>& vertices, const std::vector<GLuint>& indices)
	{
		nbIndices_ = indices.size();

		glGenVertexArrays(1, &vao_);
		glGenBuffers(1, &vbo_);
		glGenBuffers(1, &ebo_);

		glBindVertexArray(vao_);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexDesc), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, nbIndices_ * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)(sizeof(glm::vec3)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)(2 * sizeof(glm::vec3)));
		glBindVertexArray(0);
	}
	
	void GpuGeometry::draw() const {
		glBindVertexArray(vao_);
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(nbIndices_), GL_UNSIGNED_INT, (void*)0);
		glBindVertexArray(0);
	}

	GpuGeometry::~GpuGeometry()
	{
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &vbo_);
		glDeleteBuffers(1, &ebo_);
	}

}