#ifndef hook_tools_h
#define hook_tools_h

#include <iostream>
#include <curl/curl.h>

namespace Hook
{
  namespace Method
  {
    extern const std::string GET;
    extern const std::string POST;
    extern const std::string PUT;
    extern const std::string DELETE;
  }

  extern void Log(std::string str, ...);

  class Str
  {
    public:
      static std::string format(std::string str, ...);
  };
}

#endif
