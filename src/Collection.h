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
        
        enum SortingOption{
            Ascending,
            Descending
        };
        
		Collection();
        Collection(DLAPI::Client *client);
		~Collection();
	
		std::string name;
		DLAPI::Dictionary params;
		DLAPI::Client* client;
		std::vector<DLAPI::Dictionary> result;
		DLAPI::Dictionary queryArgs;

		std::string getSegments();
		std::string getSegmentsWithId();
		void create();
		void fetch();
		void update();
		void addQueryArg(std::string field, std::string operation, std::string value);
		void addQueryArg(std::string field, std::string operation, int value);
        void sort(std::string field, SortingOption order);
		std::string getQuery();
        
    private:
        std::vector<std::pair<std::string, SortingOption> > ordering;
	};
}

#endif
