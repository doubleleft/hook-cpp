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
	client->request(DLAPI::Method::GET, getSegments(), &params, getQuery());
}

std::string DLAPI::Collection::getSegments()
{
	return DLAPI::Str::format("collection/%s", name.c_str());
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
