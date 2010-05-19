///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/core/core100.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_core100_included
#define glo_core100_included

// OpenGL 1.0 functions
void glCullFace(GLenum mode);
GLenum glGetError();


GLvoid glCullFace(GLenum mode);
GLvoid glFrontFace(GLenum mode);
GLvoid glHint(GLenum target, GLenum mode);
GLvoid glLineWidth(GLfloat width);
GLvoid glPointSize(GLfloat size);
GLvoid glPolygonMode(GLenum face, GLenum mode);
GLvoid glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
GLvoid glTexParameterf(GLenum target, GLenum pname, GLfloat param);
GLvoid glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
GLvoid glTexParameteri(GLenum target, GLenum pname, GLint param);
GLvoid glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
GLvoid glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLvoid glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);





GLvoid glDrawBuffer (GLenum);
GLvoid glClear (GLbitfield);
GLvoid glClearColor (GLclampf, GLclampf, GLclampf, GLclampf);
GLvoid glClearStencil (GLint);
GLvoid glClearDepth (GLclampd);
GLvoid glStencilMask (GLuint);
GLvoid glColorMask (GLboolean, GLboolean, GLboolean, GLboolean);
GLvoid glDepthMask (GLboolean);
GLvoid glDisable (GLenum);
GLvoid glEnable (GLenum);
GLvoid glFinish (void);
GLvoid glFlush (void);
GLvoid glBlendFunc (GLenum, GLenum);
GLvoid glLogicOp (GLenum);
GLvoid glStencilFunc (GLenum, GLint, GLuint);
GLvoid glStencilOp (GLenum, GLenum, GLenum);
GLvoid glDepthFunc (GLenum);
GLvoid glPixelStoref (GLenum, GLfloat);
GLvoid glPixelStorei (GLenum, GLint);
GLvoid glReadBuffer (GLenum);
GLvoid glReadPixels (GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);


void glGetBooleanv (GLenum, GLboolean *);
void glGetDoublev (GLenum, GLdouble *);
GLenum glGetError (void);
GLvoid glGetFloatv (GLenum, GLfloat *);
GLvoid glGetIntegerv (GLenum, GLint *);
const GLubyte * glGetString (GLenum);
GLvoid glGetTexImage (GLenum, GLint, GLenum, GLenum, GLvoid *);
GLvoid glGetTexParameterfv (GLenum, GLenum, GLfloat *);
GLvoid glGetTexParameteriv (GLenum, GLenum, GLint *);
GLvoid glGetTexLevelParameterfv (GLenum, GLint, GLenum, GLfloat *);
GLvoid glGetTexLevelParameteriv (GLenum, GLint, GLenum, GLint *);
GLboolean glIsEnabled (GLenum);
GLvoid glDepthRange (GLclampd, GLclampd);
GLvoid glViewport (GLint, GLint, GLsizei, GLsizei);

typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLclampd depth);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLFINISHPROC) (void);
typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *params);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *params);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *params);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLclampd near, GLclampd far);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);



#include "core100.inl"

#endif//glo_core100_included
