#include "Collection.h"

DLAPI::Collection::Collection()
{
	name = "";
	segments = "";
	client = NULL;
}

DLAPI::Collection::~Collection()
{
	client = NULL;
}

void DLAPI::Collection::create()
{
	segments = DLAPI::Str::format("collection/%s", name.c_str());
	client->request(DLAPI::Method::POST, segments, &params);
}