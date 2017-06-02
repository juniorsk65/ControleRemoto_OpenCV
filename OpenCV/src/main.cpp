#include "../include/facedetector.h"

int main()
{
    Facedetector face;
    std::string classificador = "--cascade=haarcascade_frontalface_alt.xml";
    face.run(1, classificador.c_str());
}