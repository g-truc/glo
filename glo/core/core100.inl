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
	PFNGLGETERRORPROC GetError = 0;

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

inline GLvoid glEnable(GLenum cap)
{
#ifdef GLO_DEBUG
	if(!glo::detail::Enable)
		OutputDebugString("glEnable implementation not found");
#endif//GLO_DEBUG

	assert(glo::detail::Enable);
	glo::detail::Enable(cap);

#ifdef GLO_DEBUG
	gloCheckError("glEnable");
#endif//GLO_DEBUG

	return Result;
}

inline GLvoid glDisable(GLenum cap)
{
#ifdef GLO_DEBUG
	if(!glo::detail::Disable)
		OutputDebugString("glDisable implementation not found");
#endif//GLO_DEBUG

	assert(glo::detail::Disable);
	glo::detail::Disable(cap);

#ifdef GLO_DEBUG
	gloCheckError("glDisable");
#endif//GLO_DEBUG

	return Result;
}


