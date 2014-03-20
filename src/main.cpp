#include <iostream>
#include "dlapi.h"
 

int main(int argc, char** argv) 
{
    DLAPI::Client* client = new DLAPI::Client("http://dl-api.ddll.co", "q1uU7tFtXnLad6FIGGn2cB+gxcx64/uPoDhqe2Zn5AE=", "1");

    DLAPI::Collection collection1;
    collection1.name = "ranking";
    collection1.params.setString("name", "mauro");
    collection1.params.setNumber("age", 32);
    collection1.params.setNumber("score-rio", 10);
    collection1.params.setNumber("score-sp", 11);
    collection1.client = client;
    // collection1.create();

    DLAPI::Collection collection2;
    collection2.name = "ranking";
    collection2.client = client;
    collection2.addQueryArg("_id", "=", 195);

    collection2.fetch();
    // std::string args = "{\"q\":[[\"_id\",\"=\",93]]}";
    // collection2.fetch(args);

    // std::string args = DLAPI::Str::format("{\"where\":\"%s\",\"value\":%i}", "age", 32);

    return 0;
}