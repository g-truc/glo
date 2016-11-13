#pragma once

#include "../external/vulkan/vulkan.h"
#include "pipeline_layout.hpp"
#include <vector>
#include <array>

#define GLO_ENABLE_FRONTEND_GLL 1
#define GLO_ENABLE_FRONTEND_GL5 1

namespace glo
{
	struct range
	{
		std::size_t Offset;
		std::size_t Size;
	};

	enum
	{
		MAX_SCISSORS = 8,
		MAX_VIEWPORTS = 8
	};

	enum buffer_target
	{
		BUFFER_TARGET_INDEX
	};

	class context
	{
	public:
		context(VkDevice CurrentDevice);
		virtual ~context();

		void makeCurrent();
		void submit();
		void draw(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstVertex, std::uint32_t BaseInstance);
		void draw_indexed(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstElement, std::int32_t BaseVertex, std::uint32_t BaseInstance);
		void bind_index_buffer(VkBuffer Buffer, VkDeviceSize Offset, VkIndexType IndexType);
		void set_dynamic_scissors(std::uint32_t First, std::uint32_t Count, VkRect2D const* Rects);
		void set_dynamic_viewports(std::uint32_t First, std::uint32_t Count, VkViewport const* Viewports);

		VkCommandBuffer temp_get_command_buffer() const;
		void temp_set_queue(VkQueue CurrentQueue){this->CurrentQueue = CurrentQueue;}
		void temp_set_framebuffer(VkFramebuffer CurrentFramebuffer){this->CurrentFramebuffer = CurrentFramebuffer;}
		void temp_set_renderpass(VkRenderPass RenderPass, int32_t x, int32_t y, uint32_t Width, uint32_t Height)
		{
			this->CurrentRenderPass.RenderPass = RenderPass;
			this->CurrentRenderPass.RenderArea.offset.x = x;
			this->CurrentRenderPass.RenderArea.offset.y = y;
			this->CurrentRenderPass.RenderArea.extent.width = Width;
			this->CurrentRenderPass.RenderArea.extent.height = Height;
		}

	protected:
		enum
		{
			INVALIDATED_PIPELINE_BIT = 1 << 0,
			INVALIDATED_BIND_INDEX_BUFFER_BIT = 1 << 1,
			INVALIDATED_VIEWPORTS_BIT = 1 << 2
		};
		std::uint32_t Invalidated;

		pipeline_desc CurrentPipelineDesc;

	private:
		struct render_pass
		{
			VkRenderPass RenderPass;
			VkRect2D RenderArea;
		};

		void validate_pipeline();

		VkCommandPool CommandPool;
		std::array<VkCommandBuffer, 3> CommandBuffers;

		VkDevice CurrentDevice;
		VkQueue CurrentQueue;
		VkFramebuffer CurrentFramebuffer;
		render_pass CurrentRenderPass;
		uint32_t CurrentCommandBufferIndex;

		std::vector<VkDescriptorSetLayoutBinding> CurrentDescriptorDesc;
	};

	context* get_current_context();
}//namespace glo

#include "context.inl"
