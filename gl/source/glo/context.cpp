#include "context.hpp"
#include <cassert>

extern uint32_t g_QueueFamilyIndex;

namespace glo
{
	context::context(VkDevice CurrentDevice)
		: CommandPool(nullptr)
		, CurrentDevice(CurrentDevice)
		, CurrentCommandBufferIndex(0)
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

		VkCommandPoolCreateInfo CommandPoolCreateInfo = {};
		CommandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		CommandPoolCreateInfo.queueFamilyIndex = g_QueueFamilyIndex;//swapChain.queueNodeIndex;
		CommandPoolCreateInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
		VkResult Result = vkCreateCommandPool(this->CurrentDevice, &CommandPoolCreateInfo, nullptr, &this->CommandPool);
		assert(Result == VK_SUCCESS);

		VkCommandBufferAllocateInfo CommandBufferAllocateInfo = {};
		CommandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		CommandBufferAllocateInfo.commandPool = this->CommandPool;
		CommandBufferAllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		CommandBufferAllocateInfo.commandBufferCount = this->CommandBuffers.size();
		Result = vkAllocateCommandBuffers(this->CurrentDevice, &CommandBufferAllocateInfo, &this->CommandBuffers[0]);
		assert(Result == VK_SUCCESS);
	}

	context::~context()
	{
		vkFreeCommandBuffers(this->CurrentDevice, this->CommandPool, 1, &this->CommandBuffers[0]);
		vkDestroyCommandPool(this->CurrentDevice, this->CommandPool, nullptr);
	}

	void context::makeCurrent()
	{
		++this->CurrentCommandBufferIndex;
		if (this->CurrentCommandBufferIndex == 3)
			this->CurrentCommandBufferIndex = 0;

		VkResult Result = vkResetCommandBuffer(this->CommandBuffers[CurrentCommandBufferIndex], 0);
		assert(Result == VK_SUCCESS);

		VkCommandBufferBeginInfo CommandBufferBeginInfo = {};
		CommandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		CommandBufferBeginInfo.pNext = nullptr;
		Result = vkBeginCommandBuffer(this->CommandBuffers[CurrentCommandBufferIndex], &CommandBufferBeginInfo);
		assert(Result == VK_SUCCESS);

		VkClearValue clearValues[2];
		clearValues[0].color = {{0.1f, 0.1f, 0.1f, 1.0f}};
		clearValues[1].depthStencil = {1.0f, 0};

		VkRenderPassBeginInfo RenderPassBeginInfo = {};
		RenderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		RenderPassBeginInfo.pNext = nullptr;
		RenderPassBeginInfo.renderPass = CurrentRenderPass.RenderPass;
		RenderPassBeginInfo.renderArea = CurrentRenderPass.RenderArea;
		RenderPassBeginInfo.clearValueCount = 2;
		RenderPassBeginInfo.pClearValues = clearValues;
		RenderPassBeginInfo.framebuffer = this->CurrentFramebuffer;
		vkCmdBeginRenderPass(this->CommandBuffers[CurrentCommandBufferIndex], &RenderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
	}

	void context::submit()
	{
		vkCmdEndRenderPass(this->CommandBuffers[CurrentCommandBufferIndex]);

		VkResult Result = vkEndCommandBuffer(this->CommandBuffers[CurrentCommandBufferIndex]);
		assert(Result == VK_SUCCESS);
	}

	void context::draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance)
	{
		if(this->Invalidated & INVALIDATED_PIPELINE_BIT)
			this->validate_pipeline();

		vkCmdDraw(this->CommandBuffers[CurrentCommandBufferIndex], Count, InstanceCount, FirstVertex, BaseInstance);
	}

	void context::draw_indexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
	{
		if(this->Invalidated & INVALIDATED_PIPELINE_BIT)
			this->validate_pipeline();

		vkCmdDrawIndexed(this->CommandBuffers[CurrentCommandBufferIndex], Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
	}

	void context::bind_index_buffer(VkBuffer Buffer, VkDeviceSize Offset, VkIndexType IndexType)
	{
		vkCmdBindIndexBuffer(this->CommandBuffers[CurrentCommandBufferIndex], Buffer, Offset, IndexType);
	}

	void context::set_dynamic_scissors(std::uint32_t First, std::uint32_t Count, VkRect2D const* Rects)
	{
		vkCmdSetScissor(this->CommandBuffers[CurrentCommandBufferIndex], First, Count, Rects);
	}

	void context::set_dynamic_viewports(std::uint32_t First, std::uint32_t Count, VkViewport const* Viewports)
	{
		vkCmdSetViewport(this->CommandBuffers[CurrentCommandBufferIndex], First, Count, Viewports);
	}

	void context::validate_pipeline()
	{


		this->Invalidated &= ~INVALIDATED_PIPELINE_BIT;
	}

	VkCommandBuffer context::temp_get_command_buffer() const
	{
		return this->CommandBuffers[this->CurrentCommandBufferIndex];
	}

}//namespace glo

