#pragma once

#include "../external/vulkan/vulkan.h"
#include "pipeline_layout.hpp"
#include <vector>

namespace glo
{
	struct range
	{
		std::size_t Offset;
		std::size_t Size;
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
		virtual ~context(){}

		void draw(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstVertex, std::uint32_t BaseInstance);
		void drawIndexed(std::uint32_t Count, std::uint32_t InstanceCount, std::uint32_t FirstElement, std::int32_t BaseVertex, std::uint32_t BaseInstance);

		void tempSetCommandBuffer(VkCommandBuffer CurrentCommandBuffer) {this->CurrentCommandBuffer = CurrentCommandBuffer;}

	private:
		void validatePipeline();

		VkCommandBuffer CurrentCommandBuffer;
		pipeline_desc CurrentPipelineDesc;
		std::uint32_t Invalidated;
		std::vector<VkDescriptorSetLayoutBinding> CurrentDescriptorDesc;
	};

	context* GetCurrentContext();
}//namespace glo

#include "context.inl"
