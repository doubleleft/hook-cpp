#include "Collection.h"

Hook::Collection::Collection() : name(""), client(NULL)
{
}

Hook::Collection::Collection(Hook::Client *client) : client(client), name(""){

}


Hook::Collection::~Collection()
{
  client = NULL;
}

void Hook::Collection::create()
{
  if (client == NULL) {
    std::cout << "no client set. aborting" << std::endl;
    return;
  }
  client->request(Hook::Method::POST, getSegments(), &params, "");
}

void Hook::Collection::fetch()
{
  if (client == NULL) {
    std::cout << "no client set. aborting" << std::endl;
    return;
  }

  result.resize(0);
  Hook::Request request = client->request(Hook::Method::GET, getSegments(), &params, getQuery());

  cJSON* json = cJSON_Parse(request.response.c_str());
  if (json == NULL)
    return;

  int size = cJSON_GetArraySize(json);

  for (int i = 0; i < size; i++)
  {
    cJSON* item = cJSON_GetArrayItem(json, i);
    Hook::Dictionary dict;
    dict.fromJSONString(std::string(cJSON_Print(item)));
    result.push_back(dict);
  }

  cJSON_Delete(json);
  json = NULL;
}

void Hook::Collection::update()
{
  if (client == NULL) {
    std::cout << "no client set. aborting" << std::endl;
    return;
  }
  Hook::Request request = client->request(Hook::Method::POST, getSegmentsWithId(), &params, getQuery());
}

std::string Hook::Collection::getSegments()
{
  std::string service = Hook::Str::format("collection/%s", name.c_str());
  return service;
}

std::string Hook::Collection::getSegmentsWithId()
{
  std::string service = Hook::Str::format("collection/%s/%s", name.c_str(), params.getString("_id").c_str());
  return service;
}

void Hook::Collection::addQueryArg(std::string field, std::string operation, std::string value)
{
  int size = queryArgs.size();
  queryArgs.setString(Hook::Str::format("qa%i", size), Hook::Str::format("[\"%s\",\"%s\",\"%s\"]", field.c_str(), operation.c_str(), value.c_str()));
}

void Hook::Collection::addQueryArg(std::string field, std::string operation, int value)
{
  int size = queryArgs.size();
  queryArgs.setString(Hook::Str::format("qa%i", size), Hook::Str::format("[\"%s\",\"%s\",%i]", field.c_str(), operation.c_str(), value));
}

void Hook::Collection::sort(std::string field, Hook::Collection::SortingOption operation)
{
  ordering.push_back(std::pair<std::string, SortingOption>(field, operation));
}

std::string Hook::Collection::getQuery()
{
  int size = queryArgs.size();
  std::string str = "{\"q\":[";

  // Query
  for (int i = 0; i < size; i++)
  {
    if (i != 0) str = str.append(",");
    std::string key = queryArgs.getKeyByIndex(i);
    std::string val = queryArgs.getString(key);
    str = str.append(val);
  }
  str = str.append("]");

  // Sorting
  if (ordering.size() > 0) {
    str = str.append(", \"s\": [");
    for (int i = 0; i < ordering.size(); i++)
    {
      std::pair<std::string, SortingOption> p = ordering[i];
      if (i != 0) str = str.append(",");
      std::string key = p.first;
      std::string val = p.second == Ascending ? "asc" : "desc";
      str = str.append(Hook::Str::format("[\"%s\",\"%s\"]", key.c_str(), val.c_str()));
    }
    str = str.append("]");
  }

  str = str.append("}");

  return str;
}




