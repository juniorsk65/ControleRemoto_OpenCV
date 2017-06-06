#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h> //inet_addr

int main(int argc, char *argv[])
{
    if(argc < 2)
        return -1;
    int port_num = 66666;
    //argv[2] = port_num;
    
	int socket_desc;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    ///AF_INET         IP versão 4
    ///SOCK_STREAM     Orientado a TCP
    ///0               Protocolo

    if(socket_desc >= 0)
        printf("Socket n# %d criado com sucesso. \n", socket_desc);
    if(socket_desc == -1)
        printf("Não foi possível criar o socket. \n");

    //////////////////////////////////////////////////////////
    /////////////////      SOCKADDR_IN      //////////////////
    //////////////////////////////////////////////////////////

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);

    ///////////////////////////////////////////////////////////
    ///////////////////      CONNECT     //////////////////////
    ///////////////////////////////////////////////////////////



    int status_connect = connect(socket_desc, (const struct sockaddr *) &server, sizeof(server));
    ///sockid:           inteiro, socket to be used in connection
    ///foreignAddr:      struct sockaddr: address of the passive participant
    ///addrlen:          inteiro, sizeof(name)
    if(status_connect == 0)
        printf("Connect ocorreu com sucesso. \n");
    if(status_connect != 0)
        printf("Erro de connect. \n");

    //////////////////////////////////////////////////////////
    ///////////////////       SEND      //////////////////////
    //////////////////////////////////////////////////////////

    int i = 0;
    char buffer[255];
    for(i=0 ; i<5 ; i++){

        printf("vdc?");
        scanf("%s", buffer);
        printf("%s", buffer);

        int status_send = send(socket_desc,buffer, strlen(buffer), 0);
        ///socket_desc     Descrição do Socket
        ///msg             const void[], Mensagem a ser transmitida
        ///msgLen          int, tamanho da mensagem em bytes a ser transmitida
        ///flags           int, opções especiais, valor padrão 0

        if(status_send >= 0)
            printf("Recv com sucesso.Número de bytes transmitidos: %d.\n", status_send);
        if(status_send == -1)
            printf("Erro de SEND. \n");
        memset(&buffer, 0, sizeof(buffer));
        //bzero(buffer,256);
    }

	//////////////////////////////////////////////////////////
    ///////////////////       RECV      //////////////////////
    //////////////////////////////////////////////////////////

    int status_recv = recv(socket_desc, buffer,255,0);
    ///socket_desc     Descrição do Socket
    ///recvBuf         void[], Armazena os bytes recebidos
    ///bufLen          int, Tamanho da mensagem a ser transmitida
    ///flags           int, opções especiais, valor padrão 0

    
    if(status_recv >= 0)
        printf("Recv com sucesso.Número de bytes recebidos: %d.\n", status_recv);
    if(status_recv == -1)
        printf("Erro de RECV. \n");

    //////////////////////////////////////////////////////////
    ///////////////////       CLOSE     //////////////////////
    //////////////////////////////////////////////////////////

 	int status_close = close(socket_desc);
    ///socket_desc     Descrição do Socket

    if(status_close == 0)
        printf("Socket fechado com sucesso.\n");
    if(status_close == -1)
        printf("Erro no encerramento do socket. \n");

}
