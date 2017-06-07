#include "../include/systemcontrol.h"
#include "../include/SocketClient.h"
using namespace std;

SystemControl controle("127.0.0.1", 6666);

void SystemControl::thread_detector(){
    controle.face.run();
}

void SystemControl::thread_coordenadas(){
    int um_comando_por_vez = 0;
    while(1){
        controle.face.mutex.lock();
        //RECEBENDO COORDENADAS DO CENTRO DO ROSTO
        controle.coord_x = controle.face.getXis();
        controle.coord_y = controle.face.getYpslon();
        
        //BLOCO DE COMADOS PARA ENVIAR VIA SOCKET
        //Cabeca para a esquerda, diminui canal
         if(controle.coord_x>0 && controle.coord_x<213 && um_comando_por_vez==0){ //1/3 de 640
        //comando via socket
            cout << "DIMINUI CANAL" << endl;
            controle.signal = -1;
            um_comando_por_vez = 1;
         }
        
         // Cabeca para a direita, aumenta canal
        if(controle.coord_x>426 && controle.coord_x<640 && um_comando_por_vez==0){
        //comando via socket
            cout << "AUMENTA CANAL" << endl;
            controle.signal = 1;
            um_comando_por_vez=1;
        }

        //Cabeca para cima, aumenta volume
        if(controle.coord_y>0 && controle.coord_y<160 && um_comando_por_vez==0){
        //comando via socket
            cout << "AUMENTA VOLUME" << endl;
            um_comando_por_vez=1;
            controle.signal = 2;
        }

        //Cabeca para baixo, diminui volume
        if(controle.coord_y>320 && controle.coord_y<480 && um_comando_por_vez==0){
            //comando via socket
            cout << "DIMINUI VOLUME" << endl;
            um_comando_por_vez=1;
            controle.signal = -2;
        }
        if(controle.coord_x>213 && controle.coord_x<426 && controle.coord_y>160 && controle.coord_y<320){
        //nao enviar comando via socket
        //cout << "NADA" << endl;
            um_comando_por_vez=0;
            controle.signal = 0; 
        }
        controle.face.mutex.unlock();
    }
}

void SystemControl::thread_conexao(){
    try{
        char var = '\0';
        int um_comando_por_vez = 0;
        controle.cliente.conectar();
        while(1){
            controle.face.mutex.lock();
            if(controle.signal==1 && um_comando_por_vez==1)
            {
                //Aumenta Canal
                controle.cliente.enviar("Proximo canal", 14);
                um_comando_por_vez = 0;
            }
            else if(controle.signal==-1 && um_comando_por_vez==1){
                controle.cliente.enviar("Canal anterior", 15);
                //controle.cliente.enviar(&var, 1);
                um_comando_por_vez = 0;
            }
            else if(controle.signal==-2 && um_comando_por_vez==1){
                controle.cliente.enviar("Menos volume", 13);
                um_comando_por_vez = 0;
            }
            else if(controle.signal==2 && um_comando_por_vez==1){
                controle.cliente.enviar("Mais volume", 12);
                um_comando_por_vez = 0;
            }else{
                um_comando_por_vez = 1;
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