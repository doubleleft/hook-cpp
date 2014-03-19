#ifndef dlapi_client_h
#define dlapi_client_h

#include <iostream>
#include <curl/curl.h>
#include "Dictionary.h"
#include "Request.h"
#include "Tools.h"

namespace DLAPI
{
	namespace Method
	{
		extern const std::string GET;
		extern const std::string POST;
		extern const std::string PUT;
		extern const std::string DELETE;
	}

	class Client
	{
	public:
		Client(std::string url, std::string key, std::string appId);
		~Client();

		std::string url;
		std::string key;
		std::string appId;

		DLAPI::Request* request(std::string method, std::string segments, DLAPI::Dictionary* params);
	
	private:
		DLAPI::Dictionary headers;

		void init(std::string url, std::string key, std::string appId);
	};
}

#endif