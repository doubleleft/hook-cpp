#ifndef _dlapi_h
#define _dlapi_h

#include <iostream>
#include <curl/curl.h>
#include "cJSON.h"

namespace DLAPI
{
	class Request
	{
	public:
		Request();
		~Request();

		std::string method; 
	};

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

	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		void setString(std::string key, std::string value);	
		void setNumber(std::string key, double value);

		std::string getString(std::string key);	
		double getNumber(std::string key);

	private:
		cJSON* json;
	};
}

#endif