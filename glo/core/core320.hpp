///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/core/core320.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_core320_included
#define glo_core320_included

// OpenGL 3.2 functions
void glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data);
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params);
void glProgramParameteri(GLuint program, GLenum pname, GLint value);
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glFramebufferTextureFace(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

#include "core320.inl"

#endif//glo_core320_included
