///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-01
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/glo.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glo_included
#define glo_included

namespace glo
{
	enum profile
	{
		CORE,
		COMPATIBILITY,
		NVIDIA,
		AMD
	};

	enum version
	{
		VERSION_100,
		VERSION_110,
		VERSION_120,
		VERSION_130,
		VERSION_140,
		VERSION_150,
		VERSION_200,
		VERSION_210,
		VERSION_300,
		VERSION_310,
		VERSION_320,
		VERSION_330,
		VERSION_400
	};

	void init(profile Profile, version Version);

} //namespace glo

#endif//glo_included
