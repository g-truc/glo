#pragma once

#include "../../gl.h"
#include "../glo/context.hpp"
#include <cassert>

namespace gll
{
	class context : public glo::context
	{
	public:
		void set_primitive_topology(VkPrimitiveTopology Primitive)
		{
			this->CurrentPipelineDesc.InputAssemblyState.topology = Primitive;
			this->Invalidated |= PIPELINE_INVALIDATED;
		}

		void set_index_buffer_type(VkIndexType IndexType)
		{
			this->CurrentBinding.BindIndexBuffer.IndexType = IndexType;
			this->Invalidated |= BIND_INDEX_BUFFER_INVALIDATED;
		}

		void bind_buffer(GLenum Target, VkBuffer Buffer)
		{
			switch(Target)
			{
			case GL_ELEMENT_ARRAY_BUFFER:
				this->CurrentBinding.BindIndexBuffer.Buffer = Buffer;
				this->CurrentBinding.BindIndexBuffer.Offset = 0;
				this->Invalidated |= BIND_INDEX_BUFFER_INVALIDATED;
				break;
			default:
				assert(0);
			}
		}
	};
}//namespace gll
