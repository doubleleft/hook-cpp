#ifndef dlapi_client_h
#define dlapi_client_h

#include <iostream>
#include <curl/curl.h>
#include "Request.h"
#include "Collection.h"
#include "Dictionary.h"

namespace DLAPI
{
	class Client
	{
	public:
		Client(std::string url, std::string key, std::string appId);
		~Client();

		std::string url;
		std::string key;
		std::string appId;

		DLAPI::Request* request(std::string method, std::string segments, std::string parameters);
	
	private:
		void init(std::string url, std::string key, std::string appId);
	};
}

#endif