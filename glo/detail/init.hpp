///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/detail/init.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_detail_init_included
#define glo_detail_init_included

#include "../core/core.hpp"
#include "../compatibility/compatibility.hpp"

namespace glo
{
	bool init(
		version const & Version,
		profile const & Profile);

}//namespace glo

#include "init.inl"

#endif//glo_detail_init_included
