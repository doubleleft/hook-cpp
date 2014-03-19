#ifndef dlapi_request_h
#define dlapi_request_h

#include <iostream>
#include <curl/curl.h>
#include "Dictionary.h"

namespace DLAPI
{
	class Request
	{
	public:
		Request();
		~Request();

		std::string method;
		std::string url;
		DLAPI::Dictionary* headers;
		DLAPI::Dictionary* data;
		void* response;
		int error;

		void execute();
	};
}

#endif
