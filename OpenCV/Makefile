OBJFILES = ${wildcard ./src/*.cpp}
all:
	g++ -std=c++14 ${OBJFILES} `pkg-config --cflags --libs opencv` -pthread -o main && gcc -std=c11 ./src/Server.c -o server
clear:
	rm -rf *.o
