#include <iostream>
#include "dlapi.h"
 

int main(int argc, char** argv) 
{
    DLAPI::Client* client = new DLAPI::Client("http://dl-api.ddll.co", "q1uU7tFtXnLad6FIGGn2cB+gxcx64/uPoDhqe2Zn5AE=", "1");

    DLAPI::Collection collection1;
    collection1.name = "guarana_leaderboards";
    collection1.params.setString("name", "MDT");
    collection1.params.setString("fbid", "1235");
    collection1.client = client;
    // collection1.create();

    // DLAPI::Collection collection2;
    // collection2.name = "guarana_leaderboards";
    // collection2.client = client;
    // collection2.addQueryArg("fbid", "=", "1234");
    // collection2.fetch();

    DLAPI::Collection collection3;
    collection3.name = "guarana_leaderboards";
    collection3.params.setString("_id", "20");
    collection3.params.setString("name", "MDT");
    collection3.client = client;
    collection3.update();

    DLAPI::Collection collection2;
    collection2.name = "guarana_leaderboards";
    collection2.client = client;
    collection2.addQueryArg("fbid", "=", "1235");
    collection2.fetch();

    // std::string args = "{\"q\":[[\"_id\",\"=\",93]]}";
    // collection2.fetch(args);

    // DLAPI::Dictionary result = collection2.result;

    // DLAPI::Log("result: %i", collection2.result.size());

    return 0;
}