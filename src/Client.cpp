#include "Client.h"

const std::string DLAPI::Method::GET = "GET";
const std::string DLAPI::Method::POST = "POST";
const std::string DLAPI::Method::PUT = "PUT";
const std::string DLAPI::Method::DELETE = "DELETE";

DLAPI::Client::Client(std::string url, std::string key, std::string appId)
{
	init(url, key, appId);
}

DLAPI::Client::~Client()
{
	
}

void DLAPI::Client::init(std::string url, std::string key, std::string appId)
{
	DLAPI::Log("init - url:%s key:%s appId:%s\n", url.c_str(), key.c_str(), appId.c_str());

	this->url = url;
	this->key = key;
	this->appId = appId;

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (!curl)
	{
		DLAPI::Log("ERROR! Curl not initialized.");
		return;
	}

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	printf("\n");

	headers.setString("contentType", "Content-Type: application/json");
	headers.setString("appId", DLAPI::Str::format("X-App-Id: %s", appId.c_str()));
	headers.setString("key", DLAPI::Str::format("X-App-Key: %s", key.c_str()));
}

DLAPI::Request* DLAPI::Client::request(std::string method, std::string segments, DLAPI::Dictionary* params)
{
	DLAPI::Request* request = new DLAPI::Request();

	request->method = method;
	request->url = DLAPI::Str::format("%s/%s", url.c_str(), segments.c_str());
	request->data = params;
	request->headers = &headers;
	request->execute();
	
	return request;
}
