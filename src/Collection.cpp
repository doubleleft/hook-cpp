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

void DLAPI::Collection::fetch(std::string query)
{
	// DLAPI::Dictionary args;
	// args.fromJSONString(arguments);

	// DLAPI::Log("%s", arguments.c_str());
	// DLAPI::Log("%s", args.getCString("where"));

	// [_client GET:_segments parameters:[self query] block:block];

	client->request(DLAPI::Method::GET, getSegments(), &params, query);
}

std::string DLAPI::Collection::getSegments()
{
	return DLAPI::Str::format("collection/%s", name.c_str());
}