#ifndef dlapi_request_h
#define dlapi_request_h

#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "Dictionary.h"
#include "Tools.h"

namespace DLAPI
{
	class Request
	{
	public:
		Request();
		~Request();

		std::string method;
		std::string url;
		std::vector<std::string> headers;
		DLAPI::Dictionary* data;
		void* response;
		int error;

		void execute();
	};
}

#endif
