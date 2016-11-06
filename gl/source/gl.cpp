#include "../gl.h"
#include "context.hpp"

GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (
	GLenum Mode, GLint First, GLsizei Count, GLsizei InstanceCount, GLuint BaseInstance)
{
	gl::GetCurrentContext()->draw(Count, InstanceCount, First, BaseInstance);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(
	GLenum Mode, GLsizei Count, GLenum Type, const void* Indices, GLsizei InstanceCount, GLint BaseVertex, GLuint BaseInstance)
{
	gl::GetCurrentContext()->drawIndexed(Count, InstanceCount, (uint32_t)Indices, BaseVertex, BaseInstance);
}

GLAPI void APIENTRY glBindBuffer(GLenum Target, GLuint Buffer)
{
	
}
