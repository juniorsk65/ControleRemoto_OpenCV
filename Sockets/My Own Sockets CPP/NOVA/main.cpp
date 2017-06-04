#include <iostream>
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
//#include "server.h"
//#include "client.h"

#include "SocketClient.h"
#include "SocketServer.h"
#include <string.h>
//using namespace std;

int main(int argv, char * argc[])
{
     //server(12345);
     //client(12345, "127.0.0.1");
     //char texto[2000] = "Testando o envio com orientacao a objeto";
     char buffer[2000] = "";
     char texto_env[2000] = "O sapo não lava o pé";


     bool server;
     if(argv == 1)
     	server = true;
     else
     	server = false;

     if (server) {
         SocketServer  socketS;
         socketS = SocketServer(12345);
         std::cout<<"boot r:"<< socketS.boot();
         std::cout<<"Aceitar :"<< socketS.aceitar();
         std::cout<<"Receber :"<< socketS.receber(buffer);
         std::cout<<"Recebido: " << buffer << std::endl;
     	 socketS.encerrar() ;
     }
     else {
     	std::cout <<"Cliente"<<std::endl;
        SocketClient *socketC = new SocketClient(12345, "127.0.0.1");
        socketC->conectar();
        socketC->enviar(texto_env, strlen(texto_env));
     	socketC->encerrar();
     }

     return 0;
}
