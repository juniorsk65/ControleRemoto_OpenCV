#include <iostream>
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
//#include "server.h"
//#include "client.h"

#include "SocketClient.h"
#include "SocketServer.h"
#include <string.h>
using namespace std;

int main()
{
     //server(12345);
     //client(12345, "127.0.0.1");
     char texto[2000] = "Testando o envio com orientacao a objeto";

     bool server = false;
     if (server) {
         SocketServer  socketS = SocketServer(12345);
         socketS.boot();
         socketS.aceitar();
         socketS.receber(texto);
         cout << "Recebido: " << texto << std::endl;
     }
     else {
        SocketClient *socketC = new SocketClient(12345, "127.0.0.1");
        socketC->conectar();
        socketC->enviar(texto, strlen(texto));
     }

     return 0;
}
