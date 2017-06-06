#include "../include/systemcontrol.h"
using namespace std;

SystemControl controle;

void thread_detector(){
    controle.face.run();
}

void thread_coordenadas(){
    while(1){
        //RECEBENDO COORDENADAS DO CENTRO DO ROSTO
        controle.coord_x = controle.face.getXis();
        controle.coord_y = controle.face.getYpslon();
        
        //BLOCO DE COMADOS PARA ENVIAR VIA SOCKET
        //Cabeca para a esquerda, diminui canal
         if(controle.coord_x>0 && controle.coord_x<213){ //1/3 de 640
        //comando via socket
        cout << "DIMINUI CANAL" << endl;
         }
        
         // Cabeca para a direita, aumenta canal
        if(controle.coord_x>426 && controle.coord_x<640){
        //comando via socket
        cout << "AUMENTA CANAL" << endl;
        }

        //Cabeca para cima, aumenta volume
        if(controle.coord_y>0 && controle.coord_y<160){
        //comando via socket
        cout << "AUMENTA VOLUME" << endl;
        }

        //Cabeca para baixo, diminui volume
        if(controle.coord_y>320 && controle.coord_y<480){
        //comando via socket
        cout << "DIMINUI VOLUME" << endl;
        }
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
    thread first{&thread_detector};
    thread second{&thread_coordenadas};

    first.join();
    second.join();
}