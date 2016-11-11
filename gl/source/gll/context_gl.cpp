#include "context_gl.hpp"

namespace gll
{
	context::context()
	{
		for(std::size_t i = 0; i < glo::MAX_VIEWPORTS; ++i)
		{
			Viewports[i].x = 0;
			Viewports[i].y = 0;
			Viewports[i].width = 0;
			Viewports[i].height = 0;
			Viewports[i].minDepth = 0;
			Viewports[i].maxDepth = 1;
		}
	}

	void context::draw_indexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
	{
		if(this->Invalidated & INVALIDATED_BIND_INDEX_BUFFER_BIT)
		{
			this->bind_index_buffer(this->IndexBufferBinding.Buffer, this->IndexBufferBinding.Offset, this->IndexBufferBinding.IndexType);
			this->Invalidated &= ~INVALIDATED_BIND_INDEX_BUFFER_BIT;
		}

		if(this->Invalidated & INVALIDATED_VIEWPORTS_BIT)
		{
			this->set_dynamic_viewports(0, glo::MAX_VIEWPORTS, &Viewports[0]);
			this->Invalidated &= ~INVALIDATED_VIEWPORTS_BIT;
		}

		this->glo::context::draw_indexed(Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
	}
}//namespace gll
