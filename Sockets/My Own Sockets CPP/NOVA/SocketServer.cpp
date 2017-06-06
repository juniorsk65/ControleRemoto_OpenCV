#include "SocketServer.h"

SocketServer::SocketServer(int port_num):Socket(port_num)
{
    //ctor
}

int SocketServer::boot(){


    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);

    //////////////////////////////////////////////////////////
    ///////////////////      BIND      ///////////////////////
    //////////////////////////////////////////////////////////

    int status_bind = bind(socket_desc, (struct sockaddr *) &server, sizeof(server));
    ///socket_desc     Descrição do Socket
    ///addrport        Estrutura com o endereço e descrição do socket
    ///size            Tamanho em bytes de Estrutura

    if(status_bind == 0)
        printf("\nBind ocorreu com sucesso. \n");
    else{
        printf("\nErro de bind. \n");
        return 2;
    }

    //////////////////////////////////////////////////////////
    ///////////////////      LISTEN      /////////////////////
    //////////////////////////////////////////////////////////

    int status_listen = listen(socket_desc, 5);
    ///socket_desc     Descrição do Socket
    ///queuelen        int numero de participantes ativos esperando conectar
    if(status_listen == 0){
        printf("\nListen ocorreu com sucesso. \n");
   	    printf("\nAguardando conexao na porta. \n");
    }else{
        printf("\nErro de listen. \n");
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


    if(socket_client >= 0)
        printf("\nAccept criado com sucesso.\n");
    if(socket_client == -1){
        printf("\nErro de Accept. \n");
        return 4;
    }
    return 0;
}

int SocketServer::receber(char mensagem[]) {

	//////////////////////////////////////////////////////////
    ///////////////////       RECV      //////////////////////
    //////////////////////////////////////////////////////////
    //char buffer[2000];

	
    int i = 0;
    for(i = 0; i<5;i++){
        //bzero(buffer, 256);
        memset(&mensagem,0,sizeof(*mensagem));
        int status_recv = recv(socket_desc, &mensagem, TMAX, 0);
        ///socket_desc     Descrição do Socket
        ///recvBuf         void[], Armazena os bytes recebidos
        ///bufLen          int, Tamanho da mensagem a ser transmitida
        ///flags           int, opções especiais, valor padrão 0

        if(status_recv >= 0)
            printf("Recv com sucesso.Número de bytes recebidos: %d.\n. %s \n \n", status_recv,mensagem);
        if(status_recv == -1){
            printf("Erro de RECV. \n");
            return 5;
        }
    }
    //return recv(socket_desc, mensagem, TMAX, 0);
    //return 0;
}

//adicionar o receber no cppp e a assinatura no .h