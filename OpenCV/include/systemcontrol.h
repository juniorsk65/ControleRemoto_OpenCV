#ifndef SYSTEMCONTROL_H
#define SYSTEMCONTROL_H

#include <iostream>
#include <thread>
#include "facedetector.h"

class SystemControl {
    private:
        
    public:
        SystemControl(){}
        ~SystemControl(){}
        Facedetector face;
        int coord_x, coord_y;

        void qcomando(int x, int y);
        void detector();
        void coordenadas();

};

#endif // SYSTEMCONTROL_H