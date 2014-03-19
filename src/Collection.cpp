#include "Collection.h"

DLAPI::Collection::Collection()
{
	name = "";
	segments = "";
	client = NULL;
}

DLAPI::Collection::~Collection()
{
	
}

void DLAPI::Collection::create()
{
	client->request(DLAPI::Method::POST, segments, &params);
}