#pragma once

#include "../external/vulkan/vulkan.h"
#include "../gl/gl.h"
#include "pipeline_layout.hpp"
#include <vector>

namespace gl
{
	struct range
	{
		GLintptr Offset;
		GLsizeiptr Size;
	};

	class context
	{
		enum
		{
			PIPELINE_INVALIDATED = 1 << 0,
			DESCRIPTOR_INVALIDATED = 1 << 1
		};

	public:
		context();

		void drawElements(GLenum Mode, GLsizei Count, GLenum Type, const void* Indices, GLsizei InstanceCount, GLint BaseVertex, GLuint BaseInstance);
		void drawArrays(GLenum Mode, GLint First, GLsizei Count, GLsizei InstanceCount, GLuint BaseInstance);

		void bindBuffers(GLenum Target, GLint FirstBinding, GLsizei BindingCount, range const* Range);

		void tempSetCommandBuffer(VkCommandBuffer CurrentCommandBuffer) {this->CurrentCommandBuffer = CurrentCommandBuffer;}

	private:
		void validatePipeline();

		VkCommandBuffer CurrentCommandBuffer;
		pipeline_desc CurrentPipelineDesc;
		std::uint32_t Invalidated;
		std::vector<VkDescriptorSetLayoutBinding> CurrentDescriptorDesc;
	};

	gl::context* GetCurrentContext();
}//namespace gl

#include "context.inl"
