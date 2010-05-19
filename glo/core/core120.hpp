///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-05-19
// Updated : 2010-05-19
// Licence : This source is under MIT License
// File    : glo/core/core120.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_core120_included
#define glo_core120_included

// OpenGL 1.2 functions
void glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void glBlendEquation (GLenum mode);
void glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
void glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
void glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

#include "core120.inl"

#endif//glo_core120_included
