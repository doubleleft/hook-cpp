# g++ src/main.c -o main.o -c
# g++ src/dlapi.c -o dlapi.o -c 
# g++ -o dlapi main.o dlapi.o -lcurl

clang++ src/main.cpp src/cJSON.c src/Client.cpp src/Request.cpp src/Collection.cpp src/Dictionary.cpp src/HTTP.cpp -o dlapp -lcurl



./dlapp