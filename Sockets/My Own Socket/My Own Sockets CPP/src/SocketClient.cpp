#include "SocketClient.h"

SocketClient::SocketClient(int porta, string ipServer) : Socket(port_num)
{
    this -> ipServer = ipServer;
}

void SocketClient::conectar(){

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);

    int status_connect = connect(socket_desc, (const struct sockaddr *) &server, sizeof(server));
    ///sockid:           inteiro, socket para ser usado na conexão
    ///foreignAddr:      struct sockaddr: endereço do participante passivo
    ///addrlen:          inteiro, sizeof(name)
    if(status_connect == 0)
        printf("Connect ocorreu com sucesso. \n");
    if(status_connect != 0)
        printf("Erro de connect. \n");

}
