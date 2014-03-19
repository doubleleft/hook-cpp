#ifndef dlapi_tools_h
#define dlapi_tools_h

#include <iostream>
#include <curl/curl.h>

namespace DLAPI
{
	extern void Log(std::string str, ...);

	class Str
	{
	public:
		static std::string format(std::string str, ...);
	};
}

#endif