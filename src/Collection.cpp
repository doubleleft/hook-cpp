#include "Collection.h"

DLAPI::Collection::Collection()
{
	name = "";
	client = NULL;
}

DLAPI::Collection::~Collection()
{
	client = NULL;
}

void DLAPI::Collection::create()
{
	client->request(DLAPI::Method::POST, getSegments(), &params, "");
}

void DLAPI::Collection::fetch()
{
	result.resize(0);
	DLAPI::Request request = client->request(DLAPI::Method::GET, getSegments(), &params, getQuery());

	cJSON* json = cJSON_Parse(request.response.c_str());
	int size = cJSON_GetArraySize(json);

	for (int i = 0; i < size; i++)
	{
		cJSON* item = cJSON_GetArrayItem(json, i);
		DLAPI::Dictionary dict;
		dict.fromJSONString(std::string(cJSON_Print(item)));
		result.push_back(dict);
	}

	cJSON_Delete(json);
	json = NULL;
}

void DLAPI::Collection::update()
{
	DLAPI::Request request = client->request(DLAPI::Method::POST, getSegmentsWithId(), &params, getQuery());
}

std::string DLAPI::Collection::getSegments()
{
	std::string service = DLAPI::Str::format("collection/%s", name.c_str());
	return service;
}

std::string DLAPI::Collection::getSegmentsWithId()
{
	std::string service = DLAPI::Str::format("collection/%s/%s", name.c_str(), params.getString("_id").c_str());
	return service;
}

void DLAPI::Collection::addQueryArg(std::string field, std::string operation, std::string value)
{
	int size = queryArgs.size();
	queryArgs.setString(DLAPI::Str::format("qa%i", size), DLAPI::Str::format("[\"%s\",\"%s\",\"%s\"]", field.c_str(), operation.c_str(), value.c_str()));
}

void DLAPI::Collection::addQueryArg(std::string field, std::string operation, int value)
{
	int size = queryArgs.size();
	queryArgs.setString(DLAPI::Str::format("qa%i", size), DLAPI::Str::format("[\"%s\",\"%s\",%i]", field.c_str(), operation.c_str(), value));
}

std::string DLAPI::Collection::getQuery()
{
	int size = queryArgs.size();
	std::string str = "{\"q\":[";

	for (int i = 0; i < size; i++)
	{
		if (i != 0) str = str.append(",");
		std::string key = queryArgs.getKeyByIndex(i);
		std::string val = queryArgs.getString(key);
		str = str.append(val);
	}

	str = str.append("]}");

	return str;
}
