#ifndef __gl5_h_
#define __gl5_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdint>

typedef void* GLdevice;
typedef void* GLtexture;
typedef void* GLbuffer;
typedef void* GLpass;
typedef void* GLpipeline;

enum GLtextureTarget
{

};

enum GLbufferTarget
{

};

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

#ifdef __cplusplus
}
#endif

#endif//__gl5_h_
