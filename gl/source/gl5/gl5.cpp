#include "../../gl5.h"
#include "context.hpp"
#include <cassert>

namespace
{
	gl5::context* get_context()
	{
		return static_cast<gl5::context*>(glo::get_current_context());
	}

	VkIndexType translate_index_type(gl5_buffer_type Type)
	{
		VkIndexType const Table[] =
		{
			VK_INDEX_TYPE_UINT16, // GL5_BUFFER_TYPE_UINT16,
			VK_INDEX_TYPE_UINT32 // GL5_BUFFER_TYPE_UINT32,
		};

		return Table[Type];
	}
}//namespace

void gl5_draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance)
{
	get_context()->draw(Count, InstanceCount, FirstVertex, BaseInstance);
}

void gl5_draw_indexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
{
	get_context()->draw_indexed(Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
}

void gl5_bind_buffer(gl5_buffer_target Target, VkBuffer Buffer, uint32_t Offset, uint32_t Range, gl5_buffer_type Type)
{
	switch(Target)
	{
	case GL5_BUFFER_INDEX:
		get_context()->bind_index_buffer(Buffer, Offset, ::translate_index_type(Type));
		break;
	default:
		assert(0);
	}
}

void gl5_scissors(uint32_t First, uint32_t Count, gl5_rect const* Scissors)
{
	assert(First + Count < glo::MAX_SCISSORS);
	assert(Scissors);

	get_context()->set_dynamic_scissors(First, Count, reinterpret_cast<VkRect2D const*>(Scissors));
}

void gl5_viewports(uint32_t First, uint32_t Count, gl5_viewport const* Viewports)
{
	assert(First + Count < glo::MAX_VIEWPORTS);
	assert(Viewports);

	get_context()->set_dynamic_viewports(First, Count, reinterpret_cast<VkViewport const*>(Viewports));
}
