#include <iostream>
#include "dlapi.h"
 

int main(int argc, char** argv) 
{
    DLAPI::Client* client = new DLAPI::Client("http://dl-api.ddll.co", "q1uU7tFtXnLad6FIGGn2cB+gxcx64/uPoDhqe2Zn5AE=", "1");

    DLAPI::Collection collection;
    collection.name = "ios";
    collection.segments = "ios";
    collection.params.setString("name", "mauro");
    collection.params.setNumber("age", 32);
    collection.client = client;
    collection.create();

    return 0;
}