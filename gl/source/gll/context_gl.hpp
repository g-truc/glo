#pragma once

#include "../../gl.h"
#include "../glo/context.hpp"
#include <cassert>

namespace gll
{
	class context : public glo::context
	{
	public:
		context();

		void set_primitive_topology(VkPrimitiveTopology Primitive)
		{
			this->CurrentPipelineDesc.InputAssemblyState.topology = Primitive;
			this->Invalidated |= INVALIDATED_PIPELINE_BIT;
		}

		void set_index_buffer_type(VkIndexType IndexType)
		{
			this->IndexBufferBinding.IndexType = IndexType;
			this->Invalidated |= INVALIDATED_BIND_INDEX_BUFFER_BIT;
		}

		void set_dynamic_viewport(uint32_t Index, float x, float y, float Width, float Height)
		{
			this->Viewports[Index].x = x;
			this->Viewports[Index].y = y;
			this->Viewports[Index].width = Width;
			this->Viewports[Index].height = Height;
			this->Invalidated |= INVALIDATED_VIEWPORTS_BIT;
		}

		void set_dynamic_depth_range(uint32_t Index, float Near, float Far)
		{
			this->Viewports[Index].minDepth = Near;
			this->Viewports[Index].maxDepth = Far;
			this->Invalidated |= INVALIDATED_VIEWPORTS_BIT;
		}

		void bind_buffer(GLenum Target, VkBuffer Buffer)
		{
			switch(Target)
			{
			case GL_ELEMENT_ARRAY_BUFFER:
				this->IndexBufferBinding.Buffer = Buffer;
				this->IndexBufferBinding.Offset = 0;
				this->Invalidated |= INVALIDATED_BIND_INDEX_BUFFER_BIT;
				break;
			default:
				assert(0);
			}
		}

		void draw_indexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance);

		void flush();

	private:
		struct dynamic_viewport
		{
			VkBuffer Buffer;
			VkDeviceSize Offset;
			VkIndexType IndexType;
		};

		struct index_buffer_binding
		{
			VkBuffer Buffer;
			VkDeviceSize Offset;
			VkIndexType IndexType;
		};

		index_buffer_binding IndexBufferBinding;
		std::array<VkViewport, glo::MAX_VIEWPORTS> Viewports;
	};
}//namespace gll
