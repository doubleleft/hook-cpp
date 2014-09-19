#include "Dictionary.h"

Hook::Dictionary::Dictionary()
{
  json = cJSON_CreateObject();
}

Hook::Dictionary::~Dictionary()
{
  // if (json) cJSON_Delete(json);
  // json = NULL;
}

void Hook::Dictionary::clear()
{
  if (json) cJSON_Delete(json);
  json = cJSON_CreateObject();
}

std::string Hook::Dictionary::getKeyByIndex(int index)
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

void Hook::Dictionary::setString(std::string key, std::string value)
{
  cJSON* j = cJSON_CreateString(value.c_str());
  cJSON_AddItemToObject(json, key.c_str(), j);
}

void Hook::Dictionary::setNumber(std::string key, double value)
{
  cJSON* j = cJSON_CreateNumber(value);
  cJSON_AddItemToObject(json, key.c_str(), j);
}

std::string Hook::Dictionary::getString(std::string key)
{
  std::string result = "";
  cJSON* j = cJSON_GetObjectItem(json, key.c_str());
  if (j && j->valuestring != NULL) result = std::string(j->valuestring);
  return result;
}

const char* Hook::Dictionary::getCString(std::string key)
{
  return getString(key).c_str();
}

double Hook::Dictionary::getNumber(std::string key)
{
  double result = 0;
  cJSON* j = cJSON_GetObjectItem(json, key.c_str());
  if (j) result = j->valuedouble;
  return result;
}

int Hook::Dictionary::getInt(std::string key)
{
  return (int)getNumber(key);
}

int Hook::Dictionary::size()
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

std::string Hook::Dictionary::toURLParams()
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
        str = Hook::Str::format("%s=%d", it->string, it->valueint);
        break;
      case cJSON_String:
        str = Hook::Str::format("%s=%s", it->string, it->valuestring);
        break;
    }

    r.append(str);
    it = it->next;
    if (it) r.append("&");
  }

  return r;
}

std::string Hook::Dictionary::toJSONString()
{
  return std::string(cJSON_Print(json));
}

void Hook::Dictionary::fromJSONString(std::string str)
{
  if (json) cJSON_Delete(json);
  json = cJSON_Parse(str.c_str());
  Hook::Log("fromJSONString %s\n", cJSON_Print(json));
}
