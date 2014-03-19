#include "Request.h"



DLAPI::Request::Request()
{
	data = NULL;
	response = NULL;
	headers = NULL;
}

DLAPI::Request::~Request()
{
	
}

void DLAPI::Request::execute()
{
	printf("[DLAPI::Request] execute - method:%s url:%s\n", method.c_str(), url.c_str());

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (!curl)
	{
		printf("[DLAPI::Client] ERROR! Curl not initialized.");
		return;
	}

	curl_slist* h = NULL;
    curl_slist_append(h, headers->getCString("contentType")); 
    curl_slist_append(h, headers->getCString("appId"));
    curl_slist_append(h, headers->getCString("key"));

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data->getUrlParams().c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, h); 
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);;

	res = curl_easy_perform(curl);
	printf("\n");
	
	curl_slist_free_all(h);
	curl_easy_cleanup(curl);

	printf("\n");
	
}
