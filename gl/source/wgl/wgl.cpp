#include "../../wgl.h"
#include "../gll/context.hpp"
#include "../gl5/context.hpp"

namespace
{
	glo::context* CurrentContext = nullptr;

	enum context_attribute
	{
		CONTEXT_ATTRIBUTE_PROFILE
	};
}//namespace

HGLRC WINAPI wglCreateContextAttribsGTC(HDC hdc, HGLRC hShareContext, const int *attribList)
{
	int DefaultAttribList[1] =
	{
		WGL_CONTEXT_CORE_PROFILE_BIT_ARB // CONTEXT_ATTRIBUTE_PROFILE
	};

	int AttribIndex = 0;
	while(attribList[AttribIndex])
	{
		if(attribList[AttribIndex] == WGL_CONTEXT_PROFILE_MASK_ARB)
			DefaultAttribList[CONTEXT_ATTRIBUTE_PROFILE] = attribList[AttribIndex + 1];

		++AttribIndex;
		++AttribIndex;
	}

	glo::context* Context = nullptr;
	if(DefaultAttribList[CONTEXT_ATTRIBUTE_PROFILE] == WGL_CONTEXT_GL5_PROFILE_BIT_GTC)
		Context = new gl5::context;
	else
		Context = new gll::context;

	return (HGLRC)Context;
}

BOOL WINAPI wglDeleteContextGTC(HGLRC hglrc)
{
	glo::context* Context = (glo::context*)hglrc;
	delete Context;

	return TRUE;
}

BOOL WINAPI wglMakeCurrentGTC(HDC hdc, HGLRC hglrc)
{
	::CurrentContext = (glo::context*)hglrc;

	return TRUE;
}

HGLRC WINAPI wglGetCurrentContextGTC(VOID)
{
	return (HGLRC)::CurrentContext;
}

namespace glo
{
	context* GetCurrentContext()
	{
		return ::CurrentContext;
	}
}//namespace glo
