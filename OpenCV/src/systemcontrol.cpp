#include "../include/systemcontrol.h"
#include "../include/SocketClient.h"
using namespace std;

SystemControl controle("192.168.0.18", 85);

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
            controle.signal = -1;
            flag = 1;
         }
        
         // Cabeca para a direita, aumenta canal
        if(controle.coord_x>426 && controle.coord_x<640 && flag==0){
        //comando via socket
            cout << "AUMENTA CANAL" << endl;
            controle.signal = 1;
            flag=1;
        }

        //Cabeca para cima, aumenta volume
        if(controle.coord_y>0 && controle.coord_y<160 && flag==0){
        //comando via socket
            cout << "AUMENTA VOLUME" << endl;
            flag=1;
            controle.signal = 2;
        }

        //Cabeca para baixo, diminui volume
        if(controle.coord_y>320 && controle.coord_y<480 && flag==0){
            //comando via socket
            cout << "DIMINUI VOLUME" << endl;
            flag=1;
            controle.signal = -2;
        }
        if(controle.coord_x>213 && controle.coord_x<426 && controle.coord_y>160 && controle.coord_y<320){
        //nao enviar comando via socket
        //cout << "NADA" << endl;
            flag=0;
            controle.signal = 0; 
        }
        controle.face.mutex.unlock();
    }
}

void SystemControl::thread_conexao(){
    try{
        char var = '\0';
        int flag = 0;
        controle.cliente.conectar();
        while(1){
            controle.face.mutex.lock();
            if(controle.signal==1 && flag==1)
            {
                //Aumenta Canal
                controle.cliente.enviar("Proximo canal", 14);
                flag = 0;
            }
            else if(controle.signal==-1 && flag==1){
                controle.cliente.enviar("Canal anterior", 15);
                //controle.cliente.enviar(&var, 1);
                flag = 0;
            }
            else if(controle.signal==-2 && flag==1){
                controle.cliente.enviar("Menos volume", 13);
                flag = 0;
            }
            else if(controle.signal==2 && flag==1){
                controle.cliente.enviar("Mais volume", 12);
                flag = 0;
            }else{
                flag = 1;
                controle.cliente.enviar(&var, 1);
            }
            controle.face.mutex.unlock();
        }
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
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
    thread socket(&SystemControl::thread_conexao, &controle);

    first.join();
    second.join();
    socket.join();
}