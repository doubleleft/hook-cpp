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
	DLAPI::Log("init - url:%s key:%s appId:%s", url.c_str(), key.c_str(), appId.c_str());

	this->url = url;
	this->key = key;
	this->appId = appId;

	headers.push_back("Content-Type: application/json");
	headers.push_back(DLAPI::Str::format("X-App-Id: %s", appId.c_str()));
	headers.push_back(DLAPI::Str::format("X-App-Key: %s", key.c_str()));
}

DLAPI::Request DLAPI::Client::request(std::string method, std::string segments, DLAPI::Dictionary* paramsDict, std::string query)
{
	DLAPI::Request request;

	request.query = query;
	request.params = DLAPI::Str::format("{\"data\":%s}", paramsDict->toJSONString().c_str());
	request.url = DLAPI::Str::format("%s/%s", url.c_str(), segments.c_str());
	request.method = method;
	request.headers = headers;
	request.execute();
	
	return request;
}
