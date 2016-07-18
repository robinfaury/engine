#pragma once

#include <gpu/gpubinder.h>
#include <glm/glm.hpp>
#include <vector>

namespace Gpu {

	class GpuGeometry {
	public:
		struct VertexDesc
		{
			glm::vec3 position;
			glm::vec3 normal;
			glm::vec3 uv;
		};

		/*********BINDER***********/
		class ScopedGpuGeometryBinder : public GpuBinder {
		public:
			ScopedGpuGeometryBinder() = delete;
			ScopedGpuGeometryBinder(const GpuGeometry* geo) : geo_(geo) { bind(); }
			~ScopedGpuGeometryBinder() { release(); }
			void bind() { glBindVertexArray(geo_->vao_); OGLERROR; }
			void release() { glBindVertexArray(0); OGLERROR; }
		private:
			const GpuGeometry* geo_;
		};


		/************IMPL***********/
		GpuGeometry();

		GpuGeometry(
			const std::vector<VertexDesc>& vertices,
			const std::vector<GLuint>& indices);

		void create(
			const std::vector<VertexDesc>& vertices,
			const std::vector<GLuint>& indices);

		void draw() const;

		~GpuGeometry();

	private:
		GLuint vao_;
		GLuint vbo_;
		GLuint ebo_;
		size_t nbIndices_;
	};
}
