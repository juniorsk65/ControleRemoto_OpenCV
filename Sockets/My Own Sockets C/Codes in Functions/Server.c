#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{

    //if(argc < 3)
    //    printf("erro?");

    printf(argv[0]);
    printf(" ");
    printf(argv[1]);
    
    printf("\n");

    int socket_desc;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    ///AF_INET         IP versão 4
    ///SOCK_STREAM     Orientado a TCP
    ///0               Protocolo

    if(socket_desc >= 0)
        printf("Socket n# %d criado com sucesso. \n", socket_desc);
    if(socket_desc == -1){
        printf("Não foi possível criar o socket. \n");
        return 1;
    }


    //////////////////////////////////////////////////////////
    ////////////      SOCKADDR_IN      ///////////////////////
    //////////////////////////////////////////////////////////


    struct sockaddr_in server, client;
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
    if(status_listen == 0){
        printf("Listen ocorreu com sucesso. \n");
        printf("Aguardando conexao na porta. \n");
    }
    else{
        printf("Erro de listen. \n");
        return 3;
    }

    //////////////////////////////////////////////////////////
    ///////////////////      ACCEPT     //////////////////////
    //////////////////////////////////////////////////////////

    int clienlen = sizeof(client);
    int socket_client = accept(socket_desc, (struct sockaddr *) &client, &clienlen);
    ///socket_desc     Descrição do Socket
    ///addrport        Estrutura com o endereço e descrição do socket
    ///size            Tamanho em bytes de Estrutura


    if(socket_client >= 0)
        printf("Accept criado com sucesso.\n");
    if(socket_client == -1){
        printf("Erro de Accept. \n");
        return 4;
    }


    //////////////////////////////////////////////////////////
    ///////////////////       RECV      //////////////////////
    //////////////////////////////////////////////////////////
    char buffer[256];
    int i = 0;
    for(i = 0; i<5;i++){
        //bzero(buffer, 256);
        memset(&buffer,0,sizeof(buffer));
        int status_recv = recv(socket_client, buffer, 255, 0);
        ///socket_desc     Descrição do Socket
        ///recvBuf         void[], Armazena os bytes recebidos
        ///bufLen          int, Tamanho da mensagem a ser transmitida
        ///flags           int, opções especiais, valor padrão 0

        if(status_recv >= 0)
            printf("Recv com sucesso.Número de bytes recebidos: %d.\n. %s \n \n", status_recv,buffer);
        if(status_recv == -1){
            printf("Erro de RECV. \n");
            return 5;
        }
    }


    //////////////////////////////////////////////////////////
    ///////////////////       SEND      //////////////////////
    //////////////////////////////////////////////////////////

    char retorno[] = "Fim do recebimento!";
    retorno[19] = 'a';

    int status_send = send(socket_client,retorno,1000,0);
    ///socket_desc     Descrição do Socket
    ///msg             const void[], Mensagem a ser transmitida
    ///msgLen          int, tamanho da mensagem em bytes a ser transmitida
    ///flags           int, opções especiais, valor padrão 0

    if(status_send >= 0)
        printf("Recv com sucesso.Número de bytes transmitidos: %d.\n", status_send);
    if(status_send == -1)
        printf("Erro de SEND. \n");


    //////////////////////////////////////////////////////////
    ///////////////////       CLOSE     //////////////////////
    //////////////////////////////////////////////////////////


    int status_close_desc = close(socket_desc);
    int status_close_accept = close(socket_client);
    ///socket_desc     Descrição do Socket

    if(status_close_desc == 0 && status_close_desc == 0 )
        printf("Socket fechado com sucesso.\n");
    if(status_close_desc == -1 && status_close_desc == -1)
        printf("Erro no encerramento do socket. \n");



}
