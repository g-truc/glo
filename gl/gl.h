#ifndef __gl_h_
#define __gl_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#	define WIN32_LEAN_AND_MEAN 1
#endif
#	include <windows.h>
#endif

#include "../external/vulkan/vulkan.h"

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef GL_VERSION_1_0
#	define GL_VERSION_1_0 1
#endif

typedef void GLvoid;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;

GLAPI void APIENTRY glFlush(void);
GLAPI void APIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height);

#ifndef GL_VERSION_1_1
#	define GL_VERSION_1_1 1
#endif

#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006

#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_DOUBLE                         0x140A

#ifndef GL_VERSION_1_5
#	define GL_VERSION_1_5 1
#endif

#include <stddef.h>
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;

#define GL_ELEMENT_ARRAY_BUFFER           0x8893

//GLAPI void APIENTRY glBindBuffer(GLenum target, GLuint buffer);
GLAPI void APIENTRY glBindBuffer(GLenum target, VkBuffer Buffer);

#ifndef GL_VERSION_3_2
#	define GL_VERSION_3_2 1
#endif

#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D

#ifndef GL_VERSION_4_0
#	define GL_VERSION_4_0 1
#endif

#define GL_PATCHES                        0x000E

GLAPI void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint *v);
GLAPI void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);

#ifndef GL_VERSION_4_1
#	define GL_VERSION_4_1 1
#endif

GLAPI void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat *v);
GLAPI void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);

#ifndef GL_VERSION_4_2
#	define GL_VERSION_4_2 1
#endif

GLAPI void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);

#ifndef GL_VERSION_4_3
#	define GL_VERSION_4_3 1
#endif

//GLAPI void APIENTRY glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glBindVertexBuffer(GLuint bindingindex, VkBuffer buffer, GLintptr offset, GLsizei stride);

#ifdef __cplusplus
}
#endif

#endif//__gl_h_

