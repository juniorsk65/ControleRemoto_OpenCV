#include "../include/SocketClient.h"

SocketClient::SocketClient(int port_num, std::string ipServer) : Socket(port_num)
{
    this -> ipServer = ipServer;

    //std::cout<<port_num<<std::end;
    printf("Porta n:%d  Desc Socket:%d" ,port_num, socket_desc);

}

void SocketClient::conectar(){

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr(ipServer.c_str());
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
