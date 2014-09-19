default:
	clang -lstdc++ src/main.cpp src/cJSON.c src/Client.cpp src/Request.cpp src/Collection.cpp src/Dictionary.cpp src/Tools.cpp -o dlapp -lcurl
	./dlapp
