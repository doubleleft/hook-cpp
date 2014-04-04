#ifndef dlapi_collection_h
#define dlapi_collection_h

#include <iostream>
#include "Client.h"
#include "Dictionary.h"
#include "cJSON.h"

namespace DLAPI
{
	class Collection
	{
	public:
		Collection();
		~Collection();
	
		std::string name;
		DLAPI::Dictionary params;
		DLAPI::Client* client;
		std::vector<DLAPI::Dictionary> result;
		DLAPI::Dictionary queryArgs;

		std::string getSegments();
		void create();
		void fetch();
		void addQueryArg(std::string field, std::string operation, std::string value);
		void addQueryArg(std::string field, std::string operation, int value);
		std::string getQuery();
	};
}

#endif
