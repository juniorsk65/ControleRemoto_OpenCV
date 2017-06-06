OBJFILES = ${wildcard ./src/*.cpp}
all:
	g++ -std=c++14 ${OBJFILES} `pkg-config --cflags --libs opencv` -pthread -o main
	./main
clear: 
	rm -rf *.o