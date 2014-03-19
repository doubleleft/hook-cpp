#ifndef dlapi_collection_h
#define dlapi_collection_h

#include <iostream>
#include "Client.h"
#include "Dictionary.h"

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
		DLAPI::Dictionary result;

		std::string getSegments();
		void create();
		void fetch(std::string query);
	};
}

#endif
