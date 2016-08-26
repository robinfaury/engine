#include <gpu\gpugeometry.h>

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
		OGLERROR;
		glGenBuffers(1, &vbo_);
		OGLERROR;
		glGenBuffers(1, &ebo_);
		OGLERROR;

		glBindVertexArray(vao_);
		OGLERROR;
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
		OGLERROR;
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexDesc), &vertices[0], GL_STATIC_DRAW);
		OGLERROR;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
		OGLERROR;
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, nbIndices_ * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
		OGLERROR;

		glEnableVertexAttribArray(0);
		OGLERROR;
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)0);
		OGLERROR;
		glEnableVertexAttribArray(1);
		OGLERROR;
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)(sizeof(glm::vec3)));
		OGLERROR;
		glEnableVertexAttribArray(2);
		OGLERROR;
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexDesc), (GLvoid*)(2 * sizeof(glm::vec3)));
		OGLERROR;
		glBindVertexArray(0);
		OGLERROR;
	}
	
	void GpuGeometry::draw() const {
		glBindVertexArray(vao_);
		OGLERROR;
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(nbIndices_), GL_UNSIGNED_INT, (void*)0);
		OGLERROR;
		glBindVertexArray(0);
		OGLERROR;
	}

	GpuGeometry::~GpuGeometry()
	{
		glBindVertexArray(0);
		OGLERROR;
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		OGLERROR;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		OGLERROR;
		glDeleteBuffers(1, &vbo_);
		OGLERROR;
		glDeleteBuffers(1, &ebo_);
		OGLERROR;
	}

}