#include "SocketServer.h"

SocketServer::SocketServer(int port_num):Socket(port_num)
{
    //ctor
}

int SocketServer::boot(){


    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(12341);

    //////////////////////////////////////////////////////////
    ///////////////////      BIND      ///////////////////////
    //////////////////////////////////////////////////////////

    int status_bind = bind(socket_desc, (struct sockaddr *) &server, sizeof(server));
    ///socket_desc     Descrição do Socket
    ///addrport        Estrutura com o endereço e descrição do socket
    ///size            Tamanho em bytes de Estrutura

    if(status_bind == 0)
        printf("Bind ocorreu com sucesso. \n");
    else{
        printf("Erro de bind. \n");
        return 2;
    }

    //////////////////////////////////////////////////////////
    ///////////////////      LISTEN      /////////////////////
    //////////////////////////////////////////////////////////

    int status_listen = listen(socket_desc, 5);
    ///socket_desc     Descrição do Socket
    ///queuelen        int numero de participantes ativos esperando conectar
    if(status_listen == 0)
        printf("Listen ocorreu com sucesso. \n");
    else{
        printf("Erro de listen. \n");
        return 3;
    }
    return 0;
}

int SocketServer::aceitar() {
    socklen_t clienlen = sizeof(client);
    int socket_client = accept(socket_desc, (struct sockaddr *) &client, &clienlen);
    ///socket_desc     Descrição do Socket
    ///addrport        Estrutura com o endereço e descrição do socket
    ///size            Tamanho em bytes de Estrutura

    printf("Aguardando conexao na porta. \n");

    if(socket_client >= 0)
        printf("Accept criado com sucesso.\n");
    if(socket_client == -1){
        printf("Erro de Accept. \n");
        return 4;
    }
    return 0;
}







