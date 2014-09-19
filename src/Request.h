#ifndef Hook_request_h
#define Hook_request_h

#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "Dictionary.h"
#include "Tools.h"

namespace Hook
{
  class Request
  {
    public:
      Request();
      ~Request();

      std::string method;
      std::string url;
      std::string params;
      std::string query;
      std::vector<std::string> headers;
      Hook::Dictionary* data;
      std::string response;
      int error;

      void execute();
  };
}

#endif
