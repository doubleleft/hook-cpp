#include "Request.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static std::string curlRequest(std::string method, std::string url, std::vector<std::string> headers, std::string params, std::string query)
{
	std::string readBuffer = "";

#ifdef __APPLE__
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (!curl)
	{
		DLAPI::Log("ERROR! Curl not initialized.");
		return "";
	}

	curl_slist* headerList = NULL;
	
	for (int i = 0; i < headers.size(); i++)
	{
		const char* headerStr = headers[i].c_str(); 
		headerList = curl_slist_append(headerList, headerStr);
	}

	const char* paramsStr = params.c_str();
	const char* paramsEsc = curl_easy_escape(curl, paramsStr, strlen(paramsStr));
	// printf("%s\n", paramsStr);

	const char* queryStr = query.c_str();
	const char* queryEsc = curl_easy_escape(curl, queryStr, strlen(queryStr));

	if (method.compare(DLAPI::Method::GET) == 0)
	{
		url = DLAPI::Str::format("%s?%s", url.c_str(), queryEsc);		
	}
	
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramsStr);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(paramsStr));
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	
	res = curl_easy_perform(curl);

	curl_slist_free_all(headerList);
	curl_easy_cleanup(curl);

	printf("\n");
#endif

	return readBuffer;
}


DLAPI::Request::Request()
{
	data = NULL;
	response = "";
	params = "";
	query = "";
}

DLAPI::Request::~Request()
{
	
}

void DLAPI::Request::execute()
{
	DLAPI::Log("execute %s - url:%s params:%s query:%s", method.c_str(), url.c_str(), params.c_str(), query.c_str());
	response = curlRequest(method, url, headers, params, query);
}
