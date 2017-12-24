#pragma once

#include "C.h"
#include "Strings.h"
#include "RenderConst.h"

namespace gen
{
	class ConstLoader
	{
	private:
		ConstLoader() {

		}

	public:
		static void load()
		{
			gen::C::load();
			gen::Strings::load();
			gen::RenderConst::load();
		}
	};
}