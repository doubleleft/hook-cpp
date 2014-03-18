#include "DLApi.h"

static void log(const char* format, ...)
{
	char dest[2048 * 16];
    va_list argptr;
    va_start(argptr, format);
    vsprintf(dest, format, argptr);
    va_end(argptr);
    printf("[DLAPI] %s\n", dest);
}

DLAPI::Client::Client()
{
	log("VERSION 0.0.0.1");
}

DLAPI::Client::~Client()
{
	
}

void DLAPI::Client::init(std::string url, std::string key, std::string appId)
{
	log("init - url: %s - key: %s  - appId: %s", url.c_str(), key.c_str(), appId.c_str());

	this->url = url;
	this->key = key;
	this->appId = appId;

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (!curl)
	{
		log("ERROR! Curl not initialized.");
		return;
	}

	// curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_client_write);
    // curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    // curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	printf("\n");
}

DLAPI::Request* DLAPI::Client::request(std::string method, std::string segments, std::string parameters)
{
	// NSString *url = [NSString stringWithFormat:@"%@/%@", _url, segments];

	DLAPI::Request* request = new DLAPI::Request();
	return request;
}


// Request ---------------------------------------------------

DLAPI::Request::Request()
{

}

DLAPI::Request::~Request()
{
	
}

