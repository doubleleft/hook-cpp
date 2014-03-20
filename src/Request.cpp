#include "Request.h"

static void curlRequest(std::string method, std::string url, std::vector<std::string> headers, std::string params, std::string query)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (!curl)
	{
		DLAPI::Log("ERROR! Curl not initialized.");
		return;
	}

	curl_slist* headerList = NULL;
	
	for (int i = 0; i < headers.size(); i++)
	{
		const char* headerStr = headers[i].c_str(); 
		headerList = curl_slist_append(headerList, headerStr);
	}

	const char* paramsStr = params.c_str();
	const char* paramsEsc = curl_easy_escape(curl, paramsStr, strlen(paramsStr));

	const char* queryStr = query.c_str();
	const char* queryEsc = curl_easy_escape(curl, queryStr, strlen(queryStr));

	if (method.compare(DLAPI::Method::GET) == 0)
	{
		url = DLAPI::Str::format("%s?%s", url.c_str(), queryEsc);		
	}
	
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramsEsc);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(paramsEsc));
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
	
	res = curl_easy_perform(curl);

	curl_slist_free_all(headerList);
	curl_easy_cleanup(curl);

	printf("\n");
}


DLAPI::Request::Request()
{
	data = NULL;
	response = NULL;
	params = "";
	query = "";
}

DLAPI::Request::~Request()
{
	
}

void DLAPI::Request::execute()
{
	DLAPI::Log("execute %s - url:%s params:%s query:%s", method.c_str(), url.c_str(), params.c_str(), query.c_str());
	curlRequest(method, url, headers, params, query);
}
