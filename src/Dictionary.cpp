#include "Dictionary.h"

DLAPI::Dictionary::Dictionary()
{
	json = cJSON_CreateObject();
}

DLAPI::Dictionary::~Dictionary()
{
	cJSON_Delete(json);
	json = NULL;
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

double DLAPI::Dictionary::getNumber(std::string key)
{
	double result = 0;
	cJSON* j = cJSON_GetObjectItem(json, key.c_str());
	if (j) result = j->valuedouble;
	return result;
}