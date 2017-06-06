#include "../include/systemcontrol.h"
using namespace std;

SystemControl controle;

void SystemControl::thread_detector(){
    controle.face.run();
}

void SystemControl::thread_coordenadas(){
    int flag = 0;
    while(1){
        controle.face.mutex.lock();
        //RECEBENDO COORDENADAS DO CENTRO DO ROSTO
        controle.coord_x = controle.face.getXis();
        controle.coord_y = controle.face.getYpslon();
        
        //BLOCO DE COMADOS PARA ENVIAR VIA SOCKET
        //Cabeca para a esquerda, diminui canal
         if(controle.coord_x>0 && controle.coord_x<213 && flag==0){ //1/3 de 640
        //comando via socket
        cout << "DIMINUI CANAL" << endl;
        flag = 1;
         }
        
         // Cabeca para a direita, aumenta canal
        if(controle.coord_x>426 && controle.coord_x<640 && flag==0){
        //comando via socket
        cout << "AUMENTA CANAL" << endl;
        flag=1;
        }

        //Cabeca para cima, aumenta volume
        if(controle.coord_y>0 && controle.coord_y<160 && flag==0){
        //comando via socket
        cout << "AUMENTA VOLUME" << endl;
        flag=1;
        }

        //Cabeca para baixo, diminui volume
        if(controle.coord_y>320 && controle.coord_y<480 && flag==0){
        //comando via socket
        cout << "DIMINUI VOLUME" << endl;
        flag=1;
        }
        if(controle.coord_x>213 && controle.coord_x<426 && controle.coord_y>160 && controle.coord_y<320){
        //nao enviar comando via socket
        //cout << "NADA" << endl;
        flag=0;
        }
        controle.face.mutex.unlock();
    }
}

void SystemControl::qcomando(int x, int y){
    // Cabeca para a direita, aumenta canal
    if(x>+426){
        //comando via socket
    }
    //Cabeca para cima, aumenta volume
}

int main(){
    thread first{&SystemControl::thread_detector, &controle};
    thread second{&SystemControl::thread_coordenadas, &controle};

    first.join();
    second.join();
}