#include "../../wgl.h"
#include "../gl/context.hpp"
#include "../gl5/context.hpp"

namespace
{
	gl::context* CurrentContext = nullptr;
}//namespace

HGLRC WINAPI wglCreateContextGTC(HDC hdc)
{
	gl::context* Context = new gl::context;
	return (HGLRC)Context;
}

BOOL WINAPI wglDeleteContextGTC(HGLRC hglrc)
{
	gl::context* Context = (gl::context*)hglrc;
	delete Context;

	return TRUE;
}

BOOL WINAPI wglMakeCurrentGTC(HDC hdc, HGLRC hglrc)
{
	::CurrentContext = (gl::context*)hglrc;

	return TRUE;
}

HGLRC WINAPI wglGetCurrentContextGTC(VOID)
{
	return (HGLRC)::CurrentContext;
}

namespace gl
{
	gl::context* GetCurrentContext()
	{
		return ::CurrentContext;
	}
}//namespace gl
