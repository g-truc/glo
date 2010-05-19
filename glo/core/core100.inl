///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/core/core100.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

// OpenGL 1.0 pointers
namespace glo{
namespace detail
{
    PFNGLCULLFACEPROC CullFace = 0;
    PFNGLFRONTFACEPROC FrontFace = 0;
    PFNGLHINTPROC Hint = 0;
    PFNGLLINEWIDTHPROC LineWidth = 0;
    PFNGLPOINTSIZEPROC PointSize = 0;
    PFNGLPOLYGONMODEPROC PolygonMode = 0;
    PFNGLSCISSORPROC Scissor = 0;
    PFNGLTEXPARAMETERFPROC TexParameterf = 0;
    PFNGLTEXPARAMETERFVPROC TexParameterfv = 0;
    PFNGLTEXPARAMETERIPROC TexParameteri = 0;
    PFNGLTEXPARAMETERIVPROC TexParameteriv = 0;
    PFNGLTEXIMAGE1DPROC TexImage1D = 0;
    PFNGLTEXIMAGE2DPROC TexImage2D = 0;
    PFNGLDRAWBUFFERPROC DrawBuffer = 0;
    PFNGLCLEARPROC Clear = 0;
    PFNGLCLEARCOLORPROC ClearColor = 0;
    PFNGLCLEARSTENCILPROC ClearStencil = 0;
    PFNGLCLEARDEPTHPROC ClearDepth = 0;
    PFNGLSTENCILMASKPROC StencilMask = 0;
    PFNGLCOLORMASKPROC ColorMask = 0;
    PFNGLDEPTHMASKPROC DepthMask = 0;
    PFNGLDISABLEPROC Disable = 0;
    PFNGLENABLEPROC Enable = 0;
    PFNGLFINISHPROC Finish = 0;
    PFNGLFLUSHPROC Flush = 0;
    PFNGLBLENDFUNCPROC BlendFunc = 0;
    PFNGLLOGICOPPROC LogicOp = 0;
    PFNGLSTENCILFUNCPROC StencilFunc = 0;
    PFNGLSTENCILOPPROC StencilOp = 0;
    PFNGLDEPTHFUNCPROC DepthFunc = 0;
    PFNGLPIXELSTOREFPROC PixelStoref = 0;
    PFNGLPIXELSTOREIPROC PixelStorei = 0;
    PFNGLREADBUFFERPROC ReadBuffer = 0;
    PFNGLREADPIXELSPROC ReadPixels = 0;
    PFNGLGETBOOLEANVPROC GetBooleanv = 0;
    PFNGLGETDOUBLEVPROC GetDoublev = 0;
    PFNGLGETERRORPROC GetError = 0;
    PFNGLGETFLOATVPROC GetFloatv = 0;
    PFNGLGETINTEGERVPROC GetIntegerv = 0;
    PFNGLGETSTRINGPROC glGetString = 0;
    PFNGLGETTEXIMAGEPROC GetTexImage = 0;
    GetTexParameterfv = 0;
    GetTexParameteriv = 0;
    GetTexLevelParameterfv = 0;
    GetTexLevelParameteriv = 0;
    IsEnabled = 0;
    DepthRange = 0;
    Viewport = 0;



    PFNGLGETTEXPARAMETERFVPROC
    PFNGLGETTEXPARAMETERIVPROC
    PFNGLGETTEXLEVELPARAMETERFVPROC
    PFNGLGETTEXLEVELPARAMETERIVPROC
    PFNGLISENABLEDPROC
    PFNGLDEPTHRANGEPROC
    PFNGLVIEWPORTPROC

	inline void init110Core()
	{
		CullFace = (PFNGLCULLFACEPROC)glo::getProcAddress("glCullFace");
		GetError = (PFNGLGETERRORPROC)glo::getProcAddress("glGetError");
	}

	inline void error(char const * Function)
	{
		GLenum Error = GetError();

		switch(Error)
		{
			case GL_INVALID_ENUM:
			{
				std::string Message = std::string(Function) + " has generated a GL_INVALID_ENUM error";
				OutputDebugString(Message.c_str());
			}
			break;
			case GL_INVALID_VALUE:
			{
				std::string Message = std::string(Function) + " has generated a GL_INVALID_VALUE error";
				OutputDebugString(Message.c_str());
			}
			break;
			case GL_INVALID_OPERATION:
			{
				std::string Message = std::string(Function) + " has generated a GL_INVALID_OPERATION error";
				OutputDebugString(Message.c_str());
			}
			break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:
			{
				std::string Message = std::string(Function) + " has generated a GL_INVALID_FRAMEBUFFER_OPERATION error";
				OutputDebugString(Message.c_str());
			}
			break;
			case GL_OUT_OF_MEMORY:
			{
				std::string Message = std::string(Function) + " has generated a GL_OUT_OF_MEMORY error";
				OutputDebugString(Message.c_str());
			}
			break;
			default:
			{

			}
			break;
		}

		assert(Error == GL_NO_ERROR);
	}

}//namespace detail
}//namespace glo

// OpenGL 1.0 functions
inline void glCullFace(GLenum mode)
{
#ifdef GLO_DEBUG
	if(!glo::detail::CullFace)
		OutputDebugString("glCullFace implementation not found");
#endif//GLO_DEBUG

	assert(glo::detail::CullFace);
	glo::detail::CullFace(mode);

#ifdef GLO_DEBUG
	gloCheckError("glCullFace");
#endif//GLO_DEBUG
}

inline GLenum glGetError()
{
#ifdef GLO_DEBUG
	if(!glo::detail::GetError)
		OutputDebugString("glGetError implementation not found");
#endif//GLO_DEBUG

	assert(glo::detail::GetError);
	GLenum Result = glo::detail::GetError();

#ifdef GLO_DEBUG
	gloCheckError("glGetError");
#endif//GLO_DEBUG

	return Result;
}
