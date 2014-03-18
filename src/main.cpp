#include <iostream>
#include <map>
#include "DLApi.h"
 

int main(int argc, char** argv) 
{
    DLAPI::Client* client = new DLAPI::Client("http://dl-api.ddll.co", "q1uU7tFtXnLad6FIGGn2cB+gxcx64/uPoDhqe2Zn5AE=", "1");
    client->request("POST", "segments", "params");


    DLAPI::Dictionary dict;
    dict.setString("name", "mauro");
    dict.setNumber("age", 32);

    printf("my name: %s and age: %i \n", dict.getString("name").c_str(), (int)dict.getNumber("age"));

    return 0;
}