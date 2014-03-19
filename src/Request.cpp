#include "Request.h"

static void curlRequest(std::string method, std::string url, std::vector<std::string> headers, std::string params)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (!curl)
	{
		DLAPI::Log("ERROR! Curl not initialized.");
		return;
	}

	curl_slist* h = NULL;
	
	for (int i = 0; i < headers.size(); i++)
	{
		const char* headerStr = headers[i].c_str(); 
		h = curl_slist_append(h, headerStr);
		DLAPI::Log("header: %s", headerStr);
	}

	const char* p = params.c_str();

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, h);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, p);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(p));
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
	
	res = curl_easy_perform(curl);

	curl_slist_free_all(h);
	curl_easy_cleanup(curl);

	printf("\n");
}


DLAPI::Request::Request()
{
	data = NULL;
	response = NULL;
}

DLAPI::Request::~Request()
{
	
}

void DLAPI::Request::execute()
{
	std::string params = data->getUrlParams();
	DLAPI::Log("execute %s - url:%s params:%s", method.c_str(), url.c_str(), params.c_str());
	curlRequest(method, url, headers, params);
}
