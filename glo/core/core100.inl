///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-05-20
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
    PFNGLGETTEXPARAMETERFVPROC GetTexParameterfv = 0;
    PFNGLGETTEXPARAMETERIVPROC GetTexParameteriv = 0;
    PFNGLGETTEXLEVELPARAMETERFVPROC GetTexLevelParameterfv = 0;
    PFNGLGETTEXLEVELPARAMETERIVPROC GetTexLevelParameteriv = 0;
    PFNGLISENABLEDPROC IsEnabled = 0;
    PFNGLDEPTHRANGEPROC DepthRange = 0;
    PFNGLVIEWPORTPROC Viewport = 0;

        inline void init100Core()
	{
		CullFace = (PFNGLCULLFACEPROC)glo::getProcAddress("glCullFace");
		GetError = (PFNGLGETERRORPROC)glo::getProcAddress("glGetError");

                CullFace = (PFNGLCULLFACEPROC)glo::getProcAddress("glCullFace");
                FrontFace = (PFNGLFRONTFACEPROC)glo::getProcAddress("glFrontFace");
                Hint = (PFNGLHINTPROC)glo::getProcAddress("glHint");
                LineWidth = (PFNGLLINEWIDTHPROC)glo::getProcAddress("glLineWidth");
                PointSize = (PFNGLPOINTSIZEPROC)glo::getProcAddress("glPointSize");
                PolygonMode = (PFNGLPOLYGONMODEPROC)glo::getProcAddress("glPolygonMode");
                Scissor = (PFNGLSCISSORPROC)glo::getProcAddress("glScissor");
                TexParameterf = (PFNGLTEXPARAMETERFPROC)glo::getProcAddress("glTexParameterf");
                TexParameterfv = (PFNGLTEXPARAMETERFVPROC)glo::getProcAddress("glTexParameterfv");
                TexParameteri = (PFNGLTEXPARAMETERIPROC)glo::getProcAddress("glTexParameteri");
                TexParameteriv = (PFNGLTEXPARAMETERIVPROC)glo::getProcAddress("glTexParameteriv");
                TexImage1D = (PFNGLTEXIMAGE1DPROC)glo::getProcAddress("glTexImage1D");
                TexImage2D = (PFNGLTEXIMAGE2DPROC)glo::getProcAddress("glTexImage2D");
                DrawBuffer = (PFNGLDRAWBUFFERPROC)glo::getProcAddress("glDrawBuffer");
                Clear = (PFNGLCLEARPROC)glo::getProcAddress("glClear");
                ClearColor = (PFNGLCLEARCOLORPROC)glo::getProcAddress("glClearColor");
                ClearStencil = (PFNGLCLEARSTENCILPROC)glo::getProcAddress("glClearStencil");
                ClearDepth = (PFNGLCLEARDEPTHPROC)glo::getProcAddress("glClearDepth");
                StencilMask = (PFNGLSTENCILMASKPROC)glo::getProcAddress("glStencilMask");
                ColorMask = (PFNGLCOLORMASKPROC)glo::getProcAddress("glColorMask");
                DepthMask = (PFNGLDEPTHMASKPROC)glo::getProcAddress("glDepthMask");
                Disable = (PFNGLDISABLEPROC)glo::getProcAddress("glDisable");
                Enable = (PFNGLENABLEPROC)glo::getProcAddress("glEnable");
                Finish = (PFNGLFINISHPROC)glo::getProcAddress("glFinish");
                Flush = (PFNGLFLUSHPROC)glo::getProcAddress("glFlush");
                BlendFunc = (PFNGLBLENDFUNCPROC)glo::getProcAddress("glBlendFunc");
                LogicOp = (PFNGLLOGICOPPROC)glo::getProcAddress("glLogicOp");
                StencilFunc = (PFNGLSTENCILFUNCPROC)glo::getProcAddress("glStencilFunc");
                StencilOp = (PFNGLSTENCILOPPROC)glo::getProcAddress("glStencilOp");
                DepthFunc = (PFNGLDEPTHFUNCPROC)glo::getProcAddress("glDepthFunc");
                PixelStoref = (PFNGLPIXELSTOREFPROC)glo::getProcAddress("glPixelStoref");
                PixelStorei = (PFNGLPIXELSTOREIPROC)glo::getProcAddress("glPixelStorei");
                ReadBuffer = (PFNGLREADBUFFERPROC)glo::getProcAddress("glReadBuffer");
                ReadPixels = (PFNGLREADPIXELSPROC)glo::getProcAddress("glReadPixels");
                GetBooleanv = (PFNGLGETBOOLEANVPROC)glo::getProcAddress("glGetBooleanv");


                PFNGLGETDOUBLEVPROC GetDoublev = 0;
                PFNGLGETERRORPROC GetError = 0;
                PFNGLGETFLOATVPROC GetFloatv = 0;
                PFNGLGETINTEGERVPROC GetIntegerv = 0;
                PFNGLGETSTRINGPROC glGetString = 0;
                PFNGLGETTEXIMAGEPROC GetTexImage = 0;
                PFNGLGETTEXPARAMETERFVPROC GetTexParameterfv = 0;
                PFNGLGETTEXPARAMETERIVPROC GetTexParameteriv = 0;
                PFNGLGETTEXLEVELPARAMETERFVPROC GetTexLevelParameterfv = 0;
                PFNGLGETTEXLEVELPARAMETERIVPROC GetTexLevelParameteriv = 0;
                PFNGLISENABLEDPROC IsEnabled = 0;
                PFNGLDEPTHRANGEPROC DepthRange = 0;
                PFNGLVIEWPORTPROC Viewport = 0;
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
