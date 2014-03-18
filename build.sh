# g++ src/main.c -o main.o -c
# g++ src/dlapi.c -o dlapi.o -c 
# g++ -o dlapi main.o dlapi.o -lcurl

clang++ src/main.cpp src/DLApi.cpp -o dlapp -lcurl



./dlapp