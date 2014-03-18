#ifndef _dlapi_h
#define _dlapi_h

#include <iostream>
#include <curl/curl.h>

namespace DLAPI
{
	class Request
	{
	public:
		Request();
		~Request();
	};

	class Client
	{
	public:
		Client();
		~Client();

		std::string url;
		std::string key;
		std::string appId;

		void init(std::string url, std::string key, std::string appId);
		DLAPI::Request* request(std::string method, std::string segments, std::string parameters);
	};
}

#endif