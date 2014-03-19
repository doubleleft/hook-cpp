#ifndef dlapi_dictionary_h
#define dlapi_dictionary_h

#include <iostream>
#include "cJSON.h"
#include "Tools.h"

namespace DLAPI
{
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		void setString(std::string key, std::string value);	
		void setNumber(std::string key, double value);
		void clear();

		std::string getString(std::string key);
		const char* getCString(std::string key);
		double getNumber(std::string key);
		int getInt(std::string key);

		std::string toURLParams();
		std::string toJSONString();
		void fromJSONString(std::string str);

	private:
		cJSON* json;
	};
}

#endif
