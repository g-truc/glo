#include "../gl.h"
#include "context.hpp"

GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (
	GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
	gl::GetCurrentContext()->drawArrays(mode, first, count, instancecount, baseinstance);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(
	GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
	gl::GetCurrentContext()->drawElements(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
