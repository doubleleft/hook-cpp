#include <iostream>
#include "Hook.h"

int main(int argc, char** argv)
{
  Hook::Client* client = new Hook::Client("http://dl-api.ddll.co", "q1uU7tFtXnLad6FIGGn2cB+gxcx64/uPoDhqe2Zn5AE=", "1");

  Hook::Collection collection1;
  collection1.name = "guarana_leaderboards";
  collection1.params.setString("name", "MDT");
  collection1.params.setString("fbid", "1235");
  collection1.client = client;
  // collection1.create();

  // Hook::Collection collection2;
  // collection2.name = "guarana_leaderboards";
  // collection2.client = client;
  // collection2.addQueryArg("fbid", "=", "1234");
  // collection2.fetch();

  Hook::Collection collection3;
  collection3.name = "guarana_leaderboards";
  collection3.params.setString("_id", "20");
  collection3.params.setString("name", "MDT");
  collection3.client = client;
  collection3.update();

  Hook::Collection collection2;
  collection2.name = "guarana_leaderboards";
  collection2.client = client;
  collection2.addQueryArg("fbid", "=", "1235");
  collection2.fetch();

  // std::string args = "{\"q\":[[\"_id\",\"=\",93]]}";
  // collection2.fetch(args);

  // Hook::Dictionary result = collection2.result;

  // Hook::Log("result: %i", collection2.result.size());

  return 0;
}
