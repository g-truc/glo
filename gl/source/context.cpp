#include "context.hpp"
#include "../gl.h"
#include <cassert>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

namespace
{
	VkPrimitiveTopology translatePrimitive(GLenum Mode)
	{
		switch(Mode)
		{
		case GL_POINTS:
			return VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
		case GL_LINES:
			return VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
		case GL_LINE_STRIP:
			return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
		case GL_TRIANGLES:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		case GL_TRIANGLE_STRIP:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
		case GL_TRIANGLE_FAN:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
		case GL_LINES_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY;
		case GL_LINE_STRIP_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY;
		case GL_TRIANGLES_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY;
		case GL_TRIANGLE_STRIP_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY;
		case GL_PATCHES:
			return VK_PRIMITIVE_TOPOLOGY_PATCH_LIST;
		default:
			assert(0);
			return VK_PRIMITIVE_TOPOLOGY_MAX_ENUM;
		}
	}
}//namespace

namespace gl
{
	context::context()
		: CurrentCommandBuffer(nullptr)
		, Invalidated(0)
	{
		memset(&this->CurrentPipelineDesc, 0, sizeof(this->CurrentPipelineDesc));

		this->CurrentPipelineDesc.GraphicsPipeline.pColorBlendState = &this->CurrentPipelineDesc.ColorBlendState;
		this->CurrentPipelineDesc.GraphicsPipeline.pDepthStencilState = &this->CurrentPipelineDesc.DepthStencilState;
		this->CurrentPipelineDesc.GraphicsPipeline.pDynamicState = &this->CurrentPipelineDesc.DynamicState;
		this->CurrentPipelineDesc.GraphicsPipeline.pInputAssemblyState = &this->CurrentPipelineDesc.InputAssemblyState;
		this->CurrentPipelineDesc.GraphicsPipeline.pMultisampleState = &this->CurrentPipelineDesc.MultisampleState;
		this->CurrentPipelineDesc.GraphicsPipeline.pRasterizationState = &this->CurrentPipelineDesc.RasterizationState;
		this->CurrentPipelineDesc.GraphicsPipeline.pStages = &this->CurrentPipelineDesc.ShaderStage;
		this->CurrentPipelineDesc.GraphicsPipeline.pTessellationState = &this->CurrentPipelineDesc.TessellationState;
		this->CurrentPipelineDesc.GraphicsPipeline.pVertexInputState = &this->CurrentPipelineDesc.VertexInputState;
		this->CurrentPipelineDesc.GraphicsPipeline.pViewportState = &this->CurrentPipelineDesc.ViewportState;
	}

	void context::drawElements(GLenum Mode, GLsizei Count, GLenum Type, const void* Indices, GLsizei InstanceCount, GLint BaseVertex, GLuint BaseInstance)
	{
		this->CurrentPipelineDesc.InputAssemblyState.topology = ::translatePrimitive(Mode);

		if(this->Invalidated & PIPELINE_INVALIDATED)
			this->validatePipeline();

		vkCmdDrawIndexed(this->CurrentCommandBuffer, Count, InstanceCount, (uint32_t)Indices, BaseVertex, BaseInstance);
	}

	void context::drawArrays(GLenum Mode, GLint First, GLsizei Count, GLsizei InstanceCount, GLuint BaseInstance)
	{
		this->CurrentPipelineDesc.InputAssemblyState.topology = ::translatePrimitive(Mode);

		if(this->Invalidated & PIPELINE_INVALIDATED)
			this->validatePipeline();

		vkCmdDraw(this->CurrentCommandBuffer, Count, InstanceCount, First, BaseInstance);
	}

	void context::bindBuffers(GLenum Target, GLint FirstBinding, GLsizei BindingCount, range const* Range)
	{
		

		this->Invalidated |= DESCRIPTOR_INVALIDATED;
	}

	void context::validatePipeline()
	{
		

		this->Invalidated &= ~PIPELINE_INVALIDATED;
	}
}//namespace gl

