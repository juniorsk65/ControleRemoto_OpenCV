OBJFILES = ${wildcard ./src/*.cpp}
all:
	g++ -std=c++11 ./src/facedetector.cpp `pkg-config --cflags --libs opencv` -o main
	./main --cascade=haarcascade_frontalface_alt.xml
clear: 
	rm -rf *.o