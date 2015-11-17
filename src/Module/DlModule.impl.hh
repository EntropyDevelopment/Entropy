/*	Copyright 2013 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MODULE_DLMODULE_IMPL
#	define ENTROPY_MODULE_DLMODULE_IMPL

#	include "DlModule.hh"
#	include <dlfcn.h>

	namespace Entropy
	{
		template<typename F>
		F &DlModule::get(const std::string &name)
		{
			F *addr = nullptr;

			//2013-12-12 AMR NOTE: Source: https://groups.google.com/d/msg/comp.lang.c++.moderated/BRVEES2ypvE/ov2hUcVl2NMJ
			*(void **)(&addr) = dlsym(handle(), name.c_str());
			if(addr == nullptr)
				ENTROPY_THROW(ModuleError("dlsym error") <<
					DlOpenError(dlerror()) <<
					ModuleHandle(handle())
				);

			return *addr;
		}
	}

#endif
