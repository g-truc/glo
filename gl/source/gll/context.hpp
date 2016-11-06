#pragma once

#include "../../gl.h"
#include "../glo/context.hpp"
#include <cassert>

namespace gll
{
	class context : public glo::context
	{
	public:
		void setPrimitiveTopology(VkPrimitiveTopology Primitive)
		{
			this->CurrentPipelineDesc.InputAssemblyState.topology = Primitive;
			this->Invalidated |= PIPELINE_INVALIDATED;
		}

		void setIndexBufferType(VkIndexType IndexType)
		{
			this->CurrentBinding.BindIndexBuffer.IndexType = IndexType;
			this->Invalidated |= BIND_INDEX_BUFFER_INVALIDATED;
		}

		void bindBuffer(GLenum Target, VkBuffer Buffer)
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
