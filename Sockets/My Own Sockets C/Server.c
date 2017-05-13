#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
    int socket_desc;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    ///AF_INET         IP versão 4
    ///SOCK_STREAM     Orientado a TCP
    ///0               Protocolo

    if(socket_desc >= 0)
        printf("Socket criado com sucesso.\n");
    if(socket_desc == -1)
        printf("Não foi possível criar o socket. \n");

    //////////////////////////////////////////////////////////
    ////////////      SOCKADDR_IN      ///////////////////////
    //////////////////////////////////////////////////////////


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
        printf("O bind ocorreu com sucesso. \n");
    else
        printf("Erro de bind. \n");


    //////////////////////////////////////////////////////////
    ///////////////////      LISTEN      /////////////////////
    //////////////////////////////////////////////////////////

    int status_listen = listen(socket_desc, 2);
    ///socket_desc     Descrição do Socket
    ///queuelen        int numero de participantes ativos esperando conectar
    if(status_listen == 0)
        printf("O listen ocorreu com sucesso. \n");
    else
        printf("Erro de listen. \n");

    //////////////////////////////////////////////////////////
    ///////////////////      ACCEPT     //////////////////////
    //////////////////////////////////////////////////////////

    int s = accept(socket_desc, (struct sockaddr *) &server, sizeof(server));
    ///socket_desc     Descrição do Socket
    ///addrport        Estrutura com o endereço e descrição do socket
    ///size            Tamanho em bytes de Estrutura


    if(s >= 0)
        printf("Accept criado com sucesso.\n");
    if(s == -1)
        printf("Erro de Accept. \n");






    //accept();
    //recv();
    //send();
    //close();



}
