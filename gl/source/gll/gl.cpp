#include "../../gl.h"
#include "../external/vulkan/vulkan.h"
#include "context.hpp"
#include <cassert>

namespace
{
	gll::context* getContext()
	{
		return static_cast<gll::context*>(glo::GetCurrentContext());
	}

	VkPrimitiveTopology translatePrimitiveTopology(GLenum Mode)
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

	VkIndexType translateIndexType(GLenum Type)
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

GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (
	GLenum Mode, GLint First, GLsizei Count, GLsizei InstanceCount, GLuint BaseInstance)
{
	getContext()->setPrimitiveTopology(::translatePrimitiveTopology(Mode));
	getContext()->draw(Count, InstanceCount, First, BaseInstance);
}

GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(
	GLenum Mode, GLsizei Count, GLenum Type, const void* Indices, GLsizei InstanceCount, GLint BaseVertex, GLuint BaseInstance)
{
	getContext()->setPrimitiveTopology(::translatePrimitiveTopology(Mode));
	getContext()->setIndexBufferType(::translateIndexType(Type));
	getContext()->drawIndexed(Count, InstanceCount, (uint32_t)Indices, BaseVertex, BaseInstance);
}

GLAPI void APIENTRY glBindBuffer(GLenum Target, VkBuffer Buffer)//GLuint Buffer)
{
	getContext()->bindBuffer(Target, Buffer);
}
