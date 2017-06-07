#ifndef SYSTEMCONTROL_H
#define SYSTEMCONTROL_H

#include <iostream>
#include <thread>
#include <mutex>
#include "facedetector.h"
#include "../include/SocketClient.h"
class SystemControl {
    private:
            
    public:
        int coord_x, coord_y;
        char signal;
        SocketClient cliente;
        Facedetector face;



        SystemControl(){}
        SystemControl(std::string ip_, unsigned long port){
            cliente = SocketClient(port, ip_);
        }
        ~SystemControl(){}
        

        

        void qcomando(int x, int y);
        void thread_detector();
        void thread_coordenadas();
        void thread_conexao();

};

#endif // SYSTEMCONTROL_H
