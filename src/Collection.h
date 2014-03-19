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
		std::string segments;
		DLAPI::Dictionary params;
		DLAPI::Client* client;

		void create();
	};
}

#endif
