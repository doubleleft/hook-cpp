#include "Dictionary.h"

DLAPI::Dictionary::Dictionary()
{
	json = cJSON_CreateObject();
}

DLAPI::Dictionary::~Dictionary()
{
	// if (json) cJSON_Delete(json);
	// json = NULL;
}

void DLAPI::Dictionary::clear()
{
	if (json) cJSON_Delete(json);
	json = cJSON_CreateObject();
}

std::string DLAPI::Dictionary::getKeyByIndex(int index)
{
	std::string r = "";
	int i = 0;

	cJSON* it = json->child;
	while (it)
	{
		if (i == index)
		{
			r = std::string(it->string);
			printf("%s\n", r.c_str());
			break;
		}
		i++;
		it = it->next;
	}

	return r;
}

void DLAPI::Dictionary::setString(std::string key, std::string value)
{
	cJSON* j = cJSON_CreateString(value.c_str()); 
	cJSON_AddItemToObject(json, key.c_str(), j);
}	

void DLAPI::Dictionary::setNumber(std::string key, double value)
{
	cJSON* j = cJSON_CreateNumber(value);  
	cJSON_AddItemToObject(json, key.c_str(), j);
}

std::string DLAPI::Dictionary::getString(std::string key)
{
	std::string result = "";
	cJSON* j = cJSON_GetObjectItem(json, key.c_str());
	if (j) result = std::string(j->valuestring);
	return result;
}

const char* DLAPI::Dictionary::getCString(std::string key)
{
	return getString(key).c_str();
}

double DLAPI::Dictionary::getNumber(std::string key)
{
	double result = 0;
	cJSON* j = cJSON_GetObjectItem(json, key.c_str());
	if (j) result = j->valuedouble;
	return result;
}

int DLAPI::Dictionary::getInt(std::string key)
{
	return (int)getNumber(key);
}

int DLAPI::Dictionary::size()
{
	int r = 0;

	cJSON* it = json->child;
	while (it)
	{
		r++;
		it = it->next;
	}

	return r;
}

std::string DLAPI::Dictionary::toURLParams()
{
	std::string r = "";

	cJSON* it = json->child;
	while (it)
	{
		std::string str = "";
		const char* k = it->string;

		switch (it->type)
		{
			case cJSON_Number:
				str = DLAPI::Str::format("%s=%d", it->string, it->valueint);
			break;
			case cJSON_String:
				str = DLAPI::Str::format("%s=%s", it->string, it->valuestring);
			break;
		}

		r.append(str);
		it = it->next;
		if (it) r.append("&");
	}

	return r;
}

std::string DLAPI::Dictionary::toJSONString()
{
	return std::string(cJSON_Print(json));
}

void DLAPI::Dictionary::fromJSONString(std::string str)
{
	if (json) cJSON_Delete(json);
	json = cJSON_Parse(str.c_str());
	DLAPI::Log("fromJSONString %s\n", cJSON_Print(json));
}