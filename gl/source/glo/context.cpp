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
			this->validate_pipeline();

		vkCmdDraw(this->CurrentCommandBuffer, Count, InstanceCount, FirstVertex, BaseInstance);
	}

	void context::draw_indexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
	{
		if(GLO_ENABLE_FRONTEND_GLL && (this->Invalidated & BIND_INDEX_BUFFER_INVALIDATED))
		{
			bindIndexBufferDesc const& Desc = this->CurrentBinding.BindIndexBuffer;
			this->bind_index_buffer(Desc.Buffer, Desc.Offset, Desc.IndexType);
		}

		if(this->Invalidated & PIPELINE_INVALIDATED)
		{
			this->validate_pipeline();
		}

		vkCmdDrawIndexed(this->CurrentCommandBuffer, Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
	}

	void context::bind_index_buffer(VkBuffer Buffer, VkDeviceSize Offset, VkIndexType IndexType)
	{
		vkCmdBindIndexBuffer(this->CurrentCommandBuffer, Buffer, Offset, IndexType);
		this->Invalidated &= ~BIND_INDEX_BUFFER_INVALIDATED;
	}

	void context::set_dynamic_scissor(std::uint32_t First, std::uint32_t Count, VkRect2D const* Rect)
	{
		vkCmdSetScissor(this->CurrentCommandBuffer, First, Count, Rect);
	}

	void context::validate_pipeline()
	{


		this->Invalidated &= ~PIPELINE_INVALIDATED;
	}
}//namespace glo

