#include "../../gl.h"
#include "../external/vulkan/vulkan.h"
#include "context_gl.hpp"
#include <cassert>

namespace
{
	gll::context* get_context()
	{
		return static_cast<gll::context*>(glo::get_current_context());
	}

	VkPrimitiveTopology translate_primitive_topology(GLenum Mode)
	{
		switch(Mode)
		{
		case GL_POINTS:
			return VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
		case GL_LINES:
			return VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
		case GL_LINE_STRIP:
			return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
		case GL_TRIANGLES:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		case GL_TRIANGLE_STRIP:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
		case GL_TRIANGLE_FAN:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
		case GL_LINES_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY;
		case GL_LINE_STRIP_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY;
		case GL_TRIANGLES_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY;
		case GL_TRIANGLE_STRIP_ADJACENCY:
			return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY;
		case GL_PATCHES:
			return VK_PRIMITIVE_TOPOLOGY_PATCH_LIST;
		default:
			assert(0);
			return VK_PRIMITIVE_TOPOLOGY_MAX_ENUM;
		}
	}

	VkIndexType translate_index_type(GLenum Type)
	{
		switch(Type)
		{
		case GL_UNSIGNED_SHORT:
			return VK_INDEX_TYPE_UINT16;
		case GL_UNSIGNED_INT:
			return VK_INDEX_TYPE_UINT32;
		default:
			assert(0);
			return VK_INDEX_TYPE_MAX_ENUM;
		}
	}
}//namespace

GLAPI void APIENTRY glFlush(void)
{
	get_context()->submit();
}

GLAPI void APIENTRY glScissor(GLint x, GLint y, GLsizei Width, GLsizei Height)
{
	glScissorIndexed(0, x, y, Width, Height);
}

GLAPI void APIENTRY glBindBuffer(GLenum Target, VkBuffer Buffer)//GLuint Buffer)
{
	get_context()->bind_buffer(Target, Buffer);
}

GLAPI void APIENTRY glScissorArrayv(GLuint First, GLsizei Count, GLint const* ScissorArray)
{
	assert(First + Count < glo::MAX_SCISSORS);
	assert(ScissorArray);

	get_context()->set_dynamic_scissors(First, Count, reinterpret_cast<VkRect2D const*>(ScissorArray));
}

GLAPI void APIENTRY glScissorIndexed(GLuint Index, GLint Left, GLint Bottom, GLsizei Width, GLsizei Height)
{
	GLint const Scissor[] = {Left, Bottom, Width, Height};
	glScissorArrayv(Index, 1, Scissor);
}

GLAPI void APIENTRY glViewportIndexedf(GLuint Index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	get_context()->set_dynamic_viewport(Index, x, y, w, h);
}

GLAPI void APIENTRY glViewportIndexedfv(GLuint Index, const GLfloat *v)
{
	get_context()->set_dynamic_viewport(Index, v[0], v[1], v[2], v[3]);
}

GLAPI void APIENTRY glDepthRangeIndexed(GLuint Index, GLdouble Near, GLdouble Far)
{
	get_context()->set_dynamic_depth_range(Index, static_cast<float>(Near), static_cast<float>(Far));
}

GLAPI void APIENTRY glDrawArraysInstancedBaseInstance(GLenum Mode, GLint First, GLsizei Count, GLsizei InstanceCount, GLuint BaseInstance)
{
	get_context()->set_primitive_topology(::translate_primitive_topology(Mode));
	get_context()->draw(Count, InstanceCount, First, BaseInstance);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum Mode, GLsizei Count, GLenum Type, const void* Indices, GLsizei InstanceCount, GLint BaseVertex, GLuint BaseInstance)
{
	get_context()->set_primitive_topology(::translate_primitive_topology(Mode));
	get_context()->set_index_buffer_type(::translate_index_type(Type));
	get_context()->draw_indexed(Count, InstanceCount, (uint32_t)Indices, BaseVertex, BaseInstance);
}

GLAPI void APIENTRY glBindVertexBuffer(GLuint Bindingindex, VkBuffer Buffer, GLintptr Offset, GLsizei stride) //GLuint Buffer
{
	get_context()->bind_vertex_buffer(Buffer, Bindingindex, Offset);
}

