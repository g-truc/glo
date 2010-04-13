///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Overload Copyright (c) 2010 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-03-05
// Updated : 2010-03-05
// Licence : This source is under MIT License
// File    : glo/detail/init.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace glo{
namespace detail
{
	bool initCore(version const & Version)
	{

		return true;
	}

	bool initCompatibility(version const & Version)
	{
		return true;
	}

}//namespace detail

	bool init
	(
		version const & Version,
		profile const & Profile
	)
	{
		bool Result = true;

		switch(Profile)
		{
			case CORE:
			{
				Result &= detail::initCore(Version);
			}
			break;
			case COMPATIBILITY:
			{
				Result &= detail::initCore(Version);
				Result &= detail::initCompatibility(Version);
			}
			break;
			default:
			{
				assert(0);
				return false;
			}
			break;
		}

		return Result;
	}

}//namespace glo

