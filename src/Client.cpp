#include "Client.h"

static void log(const char* format, ...)
{
	char dest[2048 * 16];
    va_list argptr;
    va_start(argptr, format);
    vsprintf(dest, format, argptr);
    va_end(argptr);
    printf("[DLAPI] %s\n", dest);
}

static std::string format(std::string str, ...)
{
    char newStr[200];
    va_list vl;
    va_start(vl, str);
    va_end(vl);
    vsprintf(newStr, str.c_str(), vl);
    return std::string(newStr);
}

DLAPI::Client::Client(std::string url, std::string key, std::string appId)
{
	log("VERSION 0.0.0.1");
	init(url, key, appId);
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
	DLAPI::Request* request = new DLAPI::Request();

	std::string requestUrl = format("%s/%s", url.c_str(), segments.c_str());
	log(requestUrl.c_str());

	return request;
}



