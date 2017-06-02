OBJFILES = ${wildcard ./src/*.cpp}
all:
	g++ -std=c++11 ./src/main.cpp ./src/facedetector.cpp `pkg-config --cflags --libs opencv` -o main
	./main
clear: 
	rm -rf *.o