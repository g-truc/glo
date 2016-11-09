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

	struct rect
	{
		std::int32_t x;
		std::int32_t y;
		std::uint32_t width;
		std::uint32_t height;
	};

	enum
	{
		MAX_SCISSORS = 8
	};

	enum buffer_target
	{
		BUFFER_TARGET_INDEX
	};

	class context
	{
	public:
		context();
		virtual ~context(){}

		void draw(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstVertex, std::uint32_t BaseInstance);
		void draw_indexed(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstElement, std::int32_t BaseVertex, std::uint32_t BaseInstance);
		void bind_index_buffer(VkBuffer Buffer, VkDeviceSize Offset, VkIndexType IndexType);
		void set_dynamic_scissor(std::uint32_t First, std::uint32_t Count, VkRect2D const* Rect);

		void temp_set_command_buffer(VkCommandBuffer CurrentCommandBuffer) {this->CurrentCommandBuffer = CurrentCommandBuffer;}

	protected:
		enum
		{
			PIPELINE_INVALIDATED = 1 << 0,
			DESCRIPTOR_INVALIDATED = 1 << 1,
			BIND_INDEX_BUFFER_INVALIDATED = 1 << 2
		};

		struct bindIndexBufferDesc
		{
			VkBuffer Buffer;
			VkDeviceSize Offset;
			VkIndexType IndexType;
		};

		struct binding_desc
		{
			bindIndexBufferDesc BindIndexBuffer;
		};

		void validate_pipeline();

		VkCommandBuffer CurrentCommandBuffer;
		pipeline_desc CurrentPipelineDesc;
		binding_desc CurrentBinding;
		std::uint32_t Invalidated;
		std::vector<VkDescriptorSetLayoutBinding> CurrentDescriptorDesc;
	};

	context* get_current_context();
}//namespace glo

#include "context.inl"
