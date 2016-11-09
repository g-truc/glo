#ifndef __gl5_h_
#define __gl5_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdint>
#include "../external/vulkan/vulkan.h"

typedef struct gl5_offset {
	int32_t    x;
	int32_t    y;
} gl5_offset;

typedef struct gl5_extent {
	uint32_t	Width;
	uint32_t	Height;
} gl5_extent;

typedef struct gl5_rect {
	gl5_offset	Offset;
	gl5_extent	Extent;
} gl5_rect;

inline gl5_rect gl5_make_rect(int32_t x, int32_t y, uint32_t Width, uint32_t Height)
{
	gl5_rect Results;
	Results.Offset.x = x;
	Results.Offset.y = y;
	Results.Extent.Width = Width;
	Results.Extent.Height = Height;
	return Results;
}

enum gl5_buffer_target
{
	GL5_BUFFER_INDEX
};

enum gl5_buffer_type
{
	GL5_BUFFER_TYPE_UINT16 = 0,
	GL5_BUFFER_TYPE_UINT32 = 1,
	GL5_BUFFER_TYPE_NONE = 2
};

void gl5_draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance);
void gl5_draw_indexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance);
void gl5_bind_buffer(gl5_buffer_target Target, VkBuffer Buffer, uint32_t Offset, uint32_t Range, gl5_buffer_type Type);
void gl5_scissor(uint32_t First, uint32_t Count, gl5_rect const* Scissors);

#ifdef __cplusplus
}
#endif

#endif//__gl5_h_
