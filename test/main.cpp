#include "../glo/glo.hpp"

#include <cstddef>
#include <cstdint>

namespace gl
{
	typedef int sizei;
	typedef unsigned int uint;
	typedef std::ptrdiff_t sizeiptr;
	typedef std::ptrdiff_t intptr;
	typedef std::uint64_t uint64;
	typedef std::int64_t int64;
	typedef unsigned int bitfield;
	typedef unsigned char boolean;

	enum enumerant
	{

	};

    void CreateTransformFeedbacks(sizei n, uint* transformFeedback);

    void TransformFeedbackBufferBase(uint transformFeedback, uint index, uint buffer);

    void TransformFeedbackBufferRange(uint transformFeedback, uint index, uint buffer, intptr offset, sizeiptr size);

    void GetTransformFeedbackiv(uint transformFeedback, enumerant pname, int *param);

    void GetTransformFeedbacki_v(uint transformFeedback, enumerant pname, uint index, int *param);

    void GetTransformFeedbacki64_v(uint transformFeedback, enumerant pname, uint index, int64 *param);


    /* Buffer object functions */

    void CreateBuffers(sizei n, uint* buffers);

    void BufferStorage(uint buffer, sizeiptr size, const void *data, bitfield flags);

    void BufferData(uint buffer, sizeiptr size, const void *data, enumerant usage);

    void BufferSubData(uint buffer, intptr offset, sizeiptr size, const void *data);

    void CopyBufferSubData(uint readBuffer, uint writeBuffer, intptr readOffset, intptr writeOffset, sizeiptr size);

    void ClearBufferData(uint buffer, enumerant internalformat, enumerant format, enumerant type, const void * data);

    void ClearBufferSubData(uint buffer, enumerant internalformat, intptr offset, sizeiptr size, enumerant format, enumerant type, const void * data);

    void *MapBuffer(uint buffer, enumerant access);

    void *MapBufferRange(uint buffer, intptr offset, sizeiptr length, bitfield access);

    boolean UnmapBuffer(uint buffer);

    void FlushMappedBufferRange(uint buffer, intptr offset, sizeiptr length);

    void GetBufferParameteriv(uint buffer, enumerant pname, int *params);

    void GetBufferParameteri64v(uint buffer, enumerant pname, int64 *params);

    void GetBufferPointerv(uint buffer, enumerant pname, void **params);

    void GetBufferSubData(uint buffer, intptr offset, sizeiptr size, void *data);


    /* Framebuffer object functions */

    void CreateFramebuffers(sizei n, uint* ids);

    void FramebufferRenderbuffer(uint framebuffer, enumerant attachment, enumerant renderbuffertarget, uint renderbuffer);

    void FramebufferParameteri(uint framebuffer, enumerant pname, int param);

    void FramebufferTexture(uint framebuffer, enumerant attachment, uint texture, int level);

    void FramebufferTextureLayer(uint framebuffer, enumerant attachment, uint texture, int level, int layer);

    void FramebufferDrawBuffer(uint framebuffer, enumerant mode);

    void FramebufferDrawBuffers(uint framebuffer, sizei n, const enumerant *bufs);

    void FramebufferReadBuffer(uint framebuffer, enumerant mode);

    void InvalidateFramebufferData(uint framebuffer, sizei numAttachments, const enumerant *attachments);

    void InvalidateFramebufferSubData(uint framebuffer, sizei numAttachments, const enumerant *attachments, int x, int y, sizei width, sizei height);

    void ClearFramebufferiv(uint framebuffer, enumerant buffer, int drawBuffer, const int * value);

    void ClearFramebufferuiv(uint framebuffer, enumerant buffer, int drawBuffer, const uint * value);

    void ClearFramebufferfv(uint framebuffer, enumerant buffer, int drawBuffer, const float * value);

    void ClearFramebufferfi(uint framebuffer, enumerant buffer, float depth, int stencil);

    void BlitFramebuffer(uint readFramebuffer, uint drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, bitfield mask, enumerant filter);

    void CheckFramebufferStatus(uint framebuffer, enumerant target);

    void GetFramebufferParameteriv(uint framebuffer, enumerant pname, int *param);

    void GetFramebufferAttachmentParameteriv(uint framebuffer, enumerant attachment, enumerant pname, int *params);


    /* Renderbuffer object functions */

    void CreateRenderbuffers(enumerant target, sizei n, uint* renderbuffers);

    void RenderbufferStorage(uint renderbuffer, enumerant internalformat, sizei width, sizei height);

    void RenderbufferStorageMultisample(uint renderbuffer, sizei samples, enumerant internalformat, sizei width, sizei height);

    void GetRenderbufferParameteriv(uint renderbuffer, enumerant pname, int *params);


    /* Texture object functions */

    void CreateTextures(enumerant target, sizei n, uint* textures);

    void TextureBuffer(uint texture, enumerant internalformat, uint buffer);

    void TextureBufferRange(uint texture, enumerant internalformat, uint buffer, intptr offset, sizeiptr size);

    void TextureStorage1D(uint texture, sizei levels, enumerant internalformat, sizei width);

    void TextureStorage2D(uint texture, sizei levels, enumerant internalformat, sizei width, sizei height);

    void TextureStorage3D(uint texture, sizei levels, enumerant internalformat, sizei width, sizei height, sizei depth);

    void TextureStorage2DMultisample(uint texture, sizei samples, enumerant internalformat, sizei width, sizei height, boolean fixedsamplelocations);

    void TextureStorage3DMultisample(uint texture, sizei samples, enumerant internalformat, sizei width, sizei height, sizei depth, boolean fixedsamplelocations);

    void TextureSubImage1D(uint texture, int level, int xoffset, sizei width, enumerant format, enumerant type, const void *pixels);

    void TextureSubImage2D(uint texture, int level, int xoffset, int yoffset, sizei width, sizei height, enumerant format, enumerant type, const void *pixels);

    void TextureSubImage3D(uint texture, int level, int xoffset, int yoffset, int zoffset, sizei width, sizei height, sizei depth, enumerant format, enumerant type, const void *pixels);

    void CompressedTextureSubImage1D(uint texture, int level, int xoffset, sizei width, enumerant format, sizei imageSize, const void *data);

    void CompressedTextureSubImage2D(uint texture, int level, int xoffset, int yoffset, sizei width, sizei height, enumerant format, sizei imageSize, const void *data);

    void CompressedTextureSubImage3D(uint texture, int level, int xoffset, int yoffset, int zoffset, sizei width, sizei height, sizei depth, enumerant format, sizei imageSize, const void *data);

    void CopyTextureSubImage1D(uint texture, int level, int xoffset, int x, int y, sizei width);

    void CopyTextureSubImage2D(uint texture, int level, int xoffset, int yoffset, int x, int y, sizei width, sizei height);

    void CopyTextureSubImage3D(uint texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, sizei width, sizei height);

    void TextureParameterf(uint texture, enumerant pname, float param);

    void TextureParameterfv(uint texture, enumerant pname, const float *param);

    void TextureParameteri(uint texture, enumerant pname, int param);

    void TextureParameterIiv(uint texture, enumerant pname, const int *params);

    void TextureParameterIuiv(uint texture, enumerant pname, const uint *params);

    void TextureParameteriv(uint texture, enumerant pname, const int *param);

    void GenerateTextureMipmap(uint texture);

    void BindTexture(uint unit, uint texture);

    void GetTextureImage(uint texture, int level, enumerant format, enumerant type, sizei bufSize, void *pixels);

    void GetCompressedTextureImage(uint texture, int level, sizei bufSize, void *pixels);

    void GetTextureLevelParameterfv(uint texture, int level, enumerant pname, float *params);

    void GetTextureLevelParameteriv(uint texture, int level, enumerant pname, int *params);

    void GetTextureParameterfv(uint texture, enumerant pname, float *params);

    void GetTextureParameterIiv(uint texture, enumerant pname, int *params);

    void GetTextureParameterIuiv(uint texture, enumerant pname, uint *params);

    void GetTextureParameteriv(uint texture, enumerant pname, int *params);


    /* Vertex Array object functions */

    void CreateVertexArrays(sizei n, uint* arrays);

    void DisableVertexArrayAttrib(uint vaobj, uint index);

    void EnableVertexArrayAttrib(uint vaobj, uint index);

    void VertexArrayElementBuffer(uint vaobj, uint buffer);

    void VertexArrayVertexBuffer(uint vaobj, uint bindingindex, uint buffer, intptr offset, sizei stride);

    void VertexArrayVertexBuffers(uint vaobj, uint first, sizei count, const uint *buffers, const intptr *offsets, const sizei *strides);

    void VertexArrayAttribFormat(uint vaobj, uint attribindex, int size, enumerant type, boolean normalized, uint relativeoffset);

    void VertexArrayAttribIFormat(uint vaobj, uint attribindex, int size, enumerant type, uint relativeoffset);

    void VertexArrayAttribLFormat(uint vaobj, uint attribindex, int size, enumerant type, uint relativeoffset);

    void VertexArrayAttribBinding(uint vaobj, uint attribindex, uint bindingindex);

    void VertexArrayBindingDivisor(uint vaobj, uint bindingindex, uint divisor);

    void GetVertexArrayiv(uint vaobj, enumerant pname, int *param);

    void GetVertexArrayIndexediv(uint vaobj, uint index, enumerant pname, int *param);

    void GetVertexArrayIndexed64iv(uint vaobj, uint index, enumerant pname, int64 *param);


    /* Sampler object functions */

    void CreateSamplers(sizei n, uint* samplers);


    /* Program Pipeline object functions */

    void CreateProgramPipelines(sizei n, uint* pipelines);


    /* Query object functions */

    void CreateQueries(enumerant target, sizei n, uint* ids);

}//namespace gl

namespace gl
{
	class buffer
	{
	public:
		enum flag
		{
			MAP_READ_BIT = GL_MAP_READ_BIT,
			MAP_WRITE_BIT = GL_MAP_WRITE_BIT,
			MAP_PERSISTENT_BIT = GL_MAP_PERSISTENT_BIT,
			MAP_COHERENT_BIT = GL_MAP_COHERENT_BIT
		};

		buffer(sizeiptr size, const void * data, bitfield flags);

	private:
		GLuint Name;
	};

}//namespace gl

/*
        ClearTexImage -> DSAClearTexImage
        ClearTexSubImage -> DSAClearTexSubImage
        InvalidateTexSubImage -> DSAInvalidateTexSubImage
        InvalidateTexImage -> DSAInvalidateTexImage
        InvalidateBufferSubData -> DSAInvalidateBufferSubData
        InvalidateBufferData -> DSAInvalidateBufferData
        CompileShader -> DSACompileShader
        TextureView -> DSATexView
        CopyImageSubData -> DSACopyImageSubData
        UseProgramStages -> DSAProgramPipelineStages
        ProgramParameteri -> DSAProgramParameteri
        ProgramUniform* -> DSAProgramUniform*
        ProgramBinary -> DSAProgramBinary
        LinkProgram -> DSALinkProgram
        GetProgramBinary -> DSAGetProgramBinary
        GetProgramInfoLog -> DSAGetProgramInfoLog
        CreateShaderProgram -> DSACreateShaderProgram
        SamplerParameter* -> DSASamplerParameter*
        GetSamplerParameter* -> DSAGetSamplerParameter*
        ValidateProgramPipeline -> DSAValidateProgramPipeline
        UseProgramStages -> DSAProgramPipelineStages
        GetProgramPipelineInfoLog -> DSAGetProgramPipelineInfoLog
        GetProgramInterfaceiv -> DSAGetProgramInterfaceiv
        GetProgramResourceIndex -> DSAGetProgramResourceIndex
        GetProgramResourceName -> DSAGetProgramResourceName
        GetProgramResourceiv -> DSAGetProgramResourceiv
        GetProgramResourceLocation -> DSAGetProgramResourceLocation
        GetProgramResourceLocationIndex -> DSAGetProgramResourceLocationIndex
        GetAttachedShaders -> DSAGetAttachedShaders
        GetShaderiv -> DSAGetShaderiv
        GetShaderSource -> DSAGetShaderSource
        GetShaderPrecisionFormat -> DSAGetShaderPrecisionFormat
        GetProgramInfoLog -> DSAGetProgramInfoLog
        GetUniformfv -> DSAGetUniformfv
        GetUniformiv -> DSAGetUniformiv
        GetUniformuiv -> DSAGetUniformuiv
        GetUniformdv -> DSAGetUniformdv
        GetProgramStageiv -> DSAGetProgramStageiv

        CreateShader -> DSACreateShaders
        CreateProgram -> DSACreatePrograms

        GetSynciv -> DSAGetSynciv
        FenceSync -> DSAFenceSync
        WaitSync -> DSAWaitSync
        ClientWaitSync -> DSAClientWaitSync
*/

namespace glr
{
	typedef gl::sizei sizei;
	typedef gl::uint uint;
	typedef gl::sizeiptr sizeiptr;
	typedef gl::intptr intptr;
	typedef gl::uint64 uint64;
	typedef gl::int64 int64;
	typedef gl::bitfield bitfield;
	typedef gl::boolean boolean;
	typedef gl::enumerant enumerant;

	// Texture
	typedef struct TextureType
	{
		uint name;
		enumerant internalFormat;
		enumerant target;
	} *Texture;

	Texture CreateTexture(enumerant type, sizei levels, sizei samples, enumerant internalformat, sizei width, sizei height, sizei depth, boolean fixedsamplelocations);

    void ReadTexture(Texture handle, int level, int xoffset, int yoffset, int zoffset, sizei width, sizei height, sizei depth, const void *pixels);

	void CopyTexture(Texture handle, int level, int xoffset, int yoffset, int zoffset, int x, int y, int z, sizei width, sizei height, sizei depth);

    void ClearTexImage(Texture handle, int level, const void * data);

    void ClearTexImage(Texture handle, int level, int xoffset, int yoffset, int zoffset, sizei width, sizei height, sizei depth, const void * data);

    void InvalidateTextureSubImage(Texture handle, int level, int xoffset, int yoffset, int zoffset, sizei width, sizei height, sizei depth);

    void InvalidateTextureImage(Texture handle, int level);

    void TextureParameter(Texture handle, enumerant pname, float param);

    void TextureParameter(Texture handle, enumerant pname, int param);

	void GenerateTextureMipmap(Texture handle);

    void BindTexture(uint unit, Texture handle);

	// Texture Debug
    void DebugGetTextureImage(uint texture, int level, sizei bufSize, void *pixels);

    void DebugGetTextureLevelParameterfv(uint texture, int level, enumerant pname, float *params);

    void DebugGetTextureLevelParameteriv(uint texture, int level, enumerant pname, int *params);

    void DebugGetTextureParameterfv(uint texture, enumerant pname, float *params);

    void DebugGetTextureParameteriv(uint texture, enumerant pname, int *params);

	// Buffer
	typedef struct BufferType
	{
		uint name;
	} *Buffer;

    Buffer CreateBuffer(sizeiptr size, const void *data, bitfield flags);

    void CopyBuffer(Buffer readHandle, Buffer writeHandle, intptr readOffset, intptr writeOffset, sizeiptr size);

	void ClearBuffer(Buffer handle);

	void ClearBuffer(Buffer handle, intptr offset, sizeiptr size);

    void *MapBuffer(Buffer handle, intptr offset, sizeiptr length, bitfield access);

    boolean UnmapBuffer(Buffer handle);

    void FlushMappedBuffer(Buffer handle, intptr offset, sizeiptr length);

	// Buffer Debug
    void DebugGetBufferParameter(uint buffer, enumerant pname, int *params);

    void DebugGetBufferParameter(uint buffer, enumerant pname, int64 *params);

	// Framebuffer

	typedef struct FramebufferType
	{
		uint name;
	} *Framebuffer;

    Framebuffer CreateFramebuffers(Type type);

    void FramebufferParameter(Framebuffer handle, enumerant pname, int param);

    void FramebufferImage(Framebuffer handle, enumerant attachment, uint texture, int level, int layer);

    void FramebufferImageArray(Framebuffer handle, enumerant attachment, uint texture, int level);

    void FramebufferDrawBuffer(Framebuffer handle, enumerant mode);

    void FramebufferDrawBuffers(Framebuffer handle, sizei n, const enumerant *bufs);

    void FramebufferReadBuffer(Framebuffer handle, enumerant mode);

    void InvalidateFramebuffer(Framebuffer handle, sizei numAttachments, const enumerant *attachments);

    void InvalidateFramebuffer(Framebuffer handle, sizei numAttachments, const enumerant *attachments, int x, int y, sizei width, sizei height);

    void ClearFramebuffer(Framebuffer handle, enumerant buffer, int drawBuffer, const int * value);

    void ClearFramebuffer(Framebuffer handle, enumerant buffer, int drawBuffer, const uint * value);

    void ClearFramebuffer(Framebuffer handle, enumerant buffer, int drawBuffer, const float * value);

    void ClearFramebuffer(Framebuffer handle, enumerant buffer, float depth, int stencil);

	// Framebuffer Debug

    void DebugCheckFramebufferStatus(Framebuffer handle, enumerant target);

    void DebugGetFramebufferParameteriv(Framebuffer handler, enumerant pname, int *param);

    void DebugGetFramebufferAttachmentParameteriv(Framebuffer handle, enumerant attachment, enumerant pname, int *params);

}//namespace glr

int main()
{
	glo::init(glo::VERSION_320, glo::CORE);
}
