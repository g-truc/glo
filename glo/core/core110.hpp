///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-05-19
// Licence : This source is under MIT License
// File    : glo/core/core110.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_core110_included
#define glo_core110_included

// OpenGL 1.1 functions
void glDrawArrays (GLenum mode, GLint first, GLsizei count);
void glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void glGetPointerv (GLenum pname, GLvoid* *params);
void glPolygonOffset (GLfloat factor, GLfloat units);
void glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glBindTexture (GLenum target, GLuint texture);
void glDeleteTextures (GLsizei n, const GLuint *textures);
void glGenTextures (GLsizei n, GLuint *textures);
GLboolean glIsTexture (GLuint texture);

#include "core110.inl"

#endif//glo_core110_included
