#ifndef dlapi_client_h
#define dlapi_client_h

#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "Dictionary.h"
#include "Request.h"
#include "Tools.h"

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

		DLAPI::Request request(std::string method, std::string segments, DLAPI::Dictionary* paramsDict, std::string query);
	
	private:
		std::vector<std::string> headers;

		void init(std::string url, std::string key, std::string appId);
	};
}

#endif