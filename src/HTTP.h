#ifndef dlx_HTTP_h
#define dlx_HTTP_h

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <curl/curl.h>


namespace DLAPI
{
	struct HTTPResponse
	{
		size_t write(void *contents, size_t size, size_t nmemb);
	    std::vector<char> data;
	};

	class HTTPRequest
	{
	public:
	    HTTPRequest(std::string url, std::string method, void* payload);
	    ~HTTPRequest();

	    std::string url;
	    std::string method;
	    void* payload;

	    HTTPResponse response;
	    
	    void load();
	};	
}

#endif



