#ifndef hook_collection_h
#define hook_collection_h

#include <iostream>
#include "Client.h"
#include "Dictionary.h"
#include "cJSON.h"

namespace Hook
{
  class Collection
  {
    public:

      enum SortingOption{
        Ascending,
        Descending
      };

      Collection();
      Collection(Hook::Client *client);
      ~Collection();

      std::string name;
      Hook::Dictionary params;
      Hook::Client* client;
      std::vector<Hook::Dictionary> result;
      Hook::Dictionary queryArgs;

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
