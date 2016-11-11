#pragma once

#include "../glo/context.hpp"

namespace gl5
{
	class context : public glo::context
	{
	public:
		context(VkDevice Device);

	private:
	};
}//namespace gl5
