OBJFILES = ${wildcard ./src/*.cpp}
all:
	g++ -std=c++11 `pkg-config --cflags --libs opencv` ${OBJFILES} `pkg-config --libs opencv` -o main
	./main
clear: 
	rm -rf *.o