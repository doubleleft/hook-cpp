#include "HTTP.h"

static size_t http_client_write(void *ptr, size_t size, size_t nmemb, void *data) 
{
    DLAPI::HTTPResponse* response = static_cast<DLAPI::HTTPResponse*>(data);
    return response->write(ptr, size, nmemb);
}

DLAPI::HTTPRequest::HTTPRequest(std::string url, std::string method, void* payload)
{
    this->url = url;
    this->method = method;
    this->payload = payload;
}

void DLAPI::HTTPRequest::load()
{
    CURL *curl = curl_easy_init();
    
    if (!curl)
    {
        printf("[DLAPI::HTTP] error initializing cURL\n");
        return;
    }
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_client_write);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    
    CURLcode responseCode = curl_easy_perform(curl);
    // response->curlCode = responseCode;
    
    // if (responseCode != CURLE_OK)
    // {
    //     return NULL;
    // }
}


size_t DLAPI::HTTPResponse::write(void *contents, size_t size, size_t nmemb)
{
    size_t position = size * nmemb;
    data.insert(data.end(), (char*)contents, (char*)contents + position);
    return position;
}

// const char* DLAPI::HTTPResponse::string()
// {
//     return data.data();
// }

// std::vector<char> DLAPI::HTTPResponse::raw()
// {
//     return data;
// }
