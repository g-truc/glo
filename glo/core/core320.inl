///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/core/core320.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

// OpenGL 3.2 functions
namespace glo{
namespace detail
{
	PFNGLGETINTEGER64I_VPROC GetInteger64i_v = 0;
	PFNGLGETBUFFERPARAMETERI64VPROC GetBufferParameteri64v = 0;
	PFNGLPROGRAMPARAMETERIPROC ProgramParameteri = 0;
	PFNGLFRAMEBUFFERTEXTUREPROC FramebufferTexture = 0;
	PFNGLFRAMEBUFFERTEXTUREFACEPROC FramebufferTextureFace = 0;

	inline void init320Core()
	{
		// OpenGL 3.2
		GetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)glo::getProcAddress("glGetInteger64i_v");
		GetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)glo::getProcAddress("glGetBufferParameteri64v");
		ProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)glo::getProcAddress("glProgramParameteri");
		FramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)glo::getProcAddress("glFramebufferTexture");
		FramebufferTextureFace = (PFNGLFRAMEBUFFERTEXTUREFACEPROC)glo::getProcAddress("glFramebufferTextureFace");
	}

}//namespace detail
}//namespace glo
