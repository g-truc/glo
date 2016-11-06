#pragma once

#include "../external/vulkan/vulkan.h"
#include "pipeline_layout.hpp"
#include <vector>

#define GLO_ENABLE_FRONTEND_GLL 1
#define GLO_ENABLE_FRONTEND_GL5 1

namespace glo
{
	struct range
	{
		std::size_t Offset;
		std::size_t Size;
	};

	enum bufferTarget
	{
		BUFFER_TARGET_INDEX
	};

	class context
	{
	public:
		context();
		virtual ~context(){}

		void draw(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstVertex, std::uint32_t BaseInstance);
		void drawIndexed(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstElement, std::int32_t BaseVertex, std::uint32_t BaseInstance);
		void bindIndexBuffer(VkBuffer Buffer, VkDeviceSize Offset, VkIndexType IndexType);

		void tempSetCommandBuffer(VkCommandBuffer CurrentCommandBuffer) {this->CurrentCommandBuffer = CurrentCommandBuffer;}

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

		void validatePipeline();

		VkCommandBuffer CurrentCommandBuffer;
		pipeline_desc CurrentPipelineDesc;
		binding_desc CurrentBinding;
		std::uint32_t Invalidated;
		std::vector<VkDescriptorSetLayoutBinding> CurrentDescriptorDesc;
	};

	context* GetCurrentContext();
}//namespace glo

#include "context.inl"
