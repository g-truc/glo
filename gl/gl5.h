#ifndef __gl5_h_
#define __gl5_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdint>
#include "../external/vulkan/vulkan.h"

typedef void* GLdevice;
typedef void* GLtexture;
typedef void* GLbuffer;
typedef void* GLpass;
typedef void* GLpipeline;

/*
GLdevice glCreateDevice();
void glReleaseDevice(GLdevice Device);
void glFlush(GLdevice Device);
void glDraw(GLdevice Device, std::uint32_t indexCount, std::uint32_t instanceCount, std::uint32_t firstIndex, std::uint32_t vertexOffset, std::uint32_t firstInstance);

GLtexture glCreateTexture();
void glReleaseTexture(GLtexture Texture);
void glBindTexture(GLdevice Device, GLtextureTarget textureTarget, GLtexture Texture);

GLbuffer glCreateBuffer();
void glReleaseBuffer(GLbuffer Buffer);
void glBindBuffer(GLdevice Device, GLbufferTarget BufferTarget, GLbuffer Buffer);

GLpass glCreatePass();
void glReleasePass(GLpass Pass);
void glBeginPass(GLdevice Device, GLpass Pass);
void glEndPass(GLdevice Device, GLpass Pass);

GLpipeline glCreatePipeline();
void glReleasePipeline(GLpipeline Pipeline);
void glBindPipeline(GLdevice Device, GLpipeline Pipeline);
*/

enum gl5BufferTarget
{
	GL5_BUFFER_INDEX
};

enum gl5BufferType
{
	GL5_BUFFER_TYPE_UINT16 = 0,
	GL5_BUFFER_TYPE_UINT32 = 1,
	GL5_BUFFER_TYPE_NONE = 2
};

void gl5Draw(uint32_t Count, uint32_t InstanceCount,  uint32_t FirstVertex, uint32_t BaseInstance);
void gl5DrawIndexed(uint32_t Count, uint32_t InstanceCount, uint32_t FirstElement, int32_t BaseVertex, uint32_t BaseInstance);
void gl5BindBuffer(gl5BufferTarget Target, VkBuffer Buffer, uint32_t Offset, uint32_t Range, gl5BufferType Type);

#ifdef __cplusplus
}
#endif

#endif//__gl5_h_
