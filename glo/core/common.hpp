///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/core/common.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_core_common_included
#define glo_core_common_included

#include "gl3.h"
#include <string>
#include <cassert>

// OpenGL Overload functions
namespace glo{
namespace detail
{
	void error(char const * Function);

}//namespace detail

	void* getProcAddress(char const * Function);

}//namespace glo

#include "common.inl"

#endif//glo_core_common_included

