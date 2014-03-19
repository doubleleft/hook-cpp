#include "Tools.h"

void DLAPI::Log(std::string str, ...)
{
    char dest[2048 * 16];
    va_list argptr;
    va_start(argptr, str);
    vsprintf(dest, str.c_str(), argptr);
    va_end(argptr);
    printf("[DLAPI] %s\n", dest);
}

std::string DLAPI::Str::format(std::string str, ...)
{
    char newStr[2048 * 16];
    va_list vl;
    va_start(vl, str);
    va_end(vl);
    vsprintf(newStr, str.c_str(), vl);
    return std::string(newStr);
}