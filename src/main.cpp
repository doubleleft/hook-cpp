#include <iostream>
#include "DLApi.h"
 

int main(int argc, char** argv) 
{
    DLAPI::Client* client = new DLAPI::Client();
    client->init("http://dl-api.ddll.co", "q1uU7tFtXnLad6FIGGn2cB+gxcx64/uPoDhqe2Zn5AE=", "1");

    return 0;
}