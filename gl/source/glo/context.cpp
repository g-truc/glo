#include "context.hpp"
#include <cassert>

namespace glo
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

	void context::draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance)
	{
		if(this->Invalidated & PIPELINE_INVALIDATED)
			this->validatePipeline();

		vkCmdDraw(this->CurrentCommandBuffer, Count, InstanceCount, FirstVertex, BaseInstance);
	}

	void context::drawIndexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
	{
		if(this->Invalidated & PIPELINE_INVALIDATED)
			this->validatePipeline();

		vkCmdDrawIndexed(this->CurrentCommandBuffer, Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
	}

/*
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
*/
	void context::validatePipeline()
	{
		

		this->Invalidated &= ~PIPELINE_INVALIDATED;
	}
}//namespace glo

