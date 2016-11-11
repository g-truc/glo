#ifndef __gl5_h_
#define __gl5_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdint>
#include "../external/vulkan/vulkan.h"

typedef struct gl5_vec2 {
	float	x;
	float	y;
} gl5_vec2;

typedef struct gl5_ivec2 {
	int32_t		x;
	int32_t		y;
} gl5_ivec2;

typedef struct gl5_uvec2 {
	uint32_t	x;
	uint32_t	y;
} gl5_uvec2;

typedef struct gl5_rect {
	gl5_ivec2	Offset;
	gl5_uvec2	Extent;
} gl5_rect;

inline gl5_rect gl5_make_rect(int32_t x, int32_t y, uint32_t Width, uint32_t Height)
{
	gl5_rect Rect;
	Rect.Offset.x = x;
	Rect.Offset.y = y;
	Rect.Extent.x = Width;
	Rect.Extent.y = Height;
	return Rect;
}

typedef struct gl5_viewport {
	gl5_vec2 Offset;
	gl5_vec2 Extent;
	gl5_vec2 Depth;
} gl5_viewport;

inline gl5_viewport gl5_make_viewport(float x, float y, float Width, float Height, float MinDepth, float MaxDepth)
{
	gl5_viewport Viewport;
	Viewport.Offset.x = x;
	Viewport.Offset.y = y;
	Viewport.Extent.x = Width;
	Viewport.Extent.y = Height;
	Viewport.Depth.x = MinDepth;
	Viewport.Depth.y = MaxDepth;
	return Viewport;
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
void gl5_scissors(uint32_t First, uint32_t Count, gl5_rect const* Scissors);
void gl5_viewports(uint32_t First, uint32_t Count, gl5_viewport const* Viewports);
void gl5_flush();

#ifdef __cplusplus
}
#endif

#endif//__gl5_h_
