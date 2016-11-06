#include "../../gl5.h"
#include "context.hpp"
#include <cassert>

namespace
{
	gl5::context* getContext()
	{
		return static_cast<gl5::context*>(glo::GetCurrentContext());
	}

	VkIndexType translateIndexType(gl5BufferType Type)
	{
		VkIndexType const Table[] =
		{
			VK_INDEX_TYPE_UINT16, // GL5_BUFFER_TYPE_UINT16,
			VK_INDEX_TYPE_UINT32 // GL5_BUFFER_TYPE_UINT32,
		};

		return Table[Type];
	}
}//namespace

void gl5Draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance)
{
	getContext()->draw(Count, InstanceCount, FirstVertex, BaseInstance);
}

void gl5DrawIndexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
{
	getContext()->drawIndexed(Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
}

void gl5BindBuffer(gl5BufferTarget Target, VkBuffer Buffer, uint32_t Offset, uint32_t Range, gl5BufferType Type)
{
	switch(Target)
	{
	case GL5_BUFFER_INDEX:
		getContext()->bindIndexBuffer(Buffer, Offset, ::translateIndexType(Type));
		break;
	default:
		assert(0);
	}
}

