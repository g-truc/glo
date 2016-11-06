#include "../../gl5.h"
#include "context.hpp"

void gl5Draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance)
{
	gl::GetCurrentContext()->draw(Count, InstanceCount, FirstVertex, BaseInstance);
}

void gl5DrawIndexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance)
{
	gl::GetCurrentContext()->drawIndexed(Count, InstanceCount, FirstElement, BaseVertex, BaseInstance);
}


