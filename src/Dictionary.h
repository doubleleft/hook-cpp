#ifndef dlapi_dictionary_h
#define dlapi_dictionary_h

#include <iostream>
#include "cJSON.h"

namespace DLAPI
{
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		void setString(std::string key, std::string value);	
		void setNumber(std::string key, double value);

		std::string getString(std::string key);	
		double getNumber(std::string key);

	private:
		cJSON* json;
	};
}

#endif
