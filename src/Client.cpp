#include "Client.h"

const std::string Hook::Method::GET = "GET";
const std::string Hook::Method::POST = "POST";
const std::string Hook::Method::PUT = "PUT";
const std::string Hook::Method::DELETE = "DELETE";

Hook::Client::Client(std::string url, std::string key, std::string appId)
{
  init(url, key, appId);
}

Hook::Client::~Client()
{

}

void Hook::Client::init(std::string url, std::string key, std::string appId)
{
  Hook::Log("init - url:%s key:%s appId:%s", url.c_str(), key.c_str(), appId.c_str());

  this->url = url;
  this->key = key;
  this->appId = appId;

  headers.push_back("Content-Type: application/json");
  headers.push_back(Hook::Str::format("X-App-Id: %s", appId.c_str()));
  headers.push_back(Hook::Str::format("X-App-Key: %s", key.c_str()));
}

Hook::Request Hook::Client::request(std::string method, std::string segments, Hook::Dictionary* paramsDict, std::string query)
{
  Hook::Request request;

  request.query = query;
  request.params = Hook::Str::format("{\"data\":%s}", paramsDict->toJSONString().c_str());
  request.url = Hook::Str::format("%s/%s", url.c_str(), segments.c_str());
  request.method = method;
  request.headers = headers;
  request.execute();

  return request;
}
