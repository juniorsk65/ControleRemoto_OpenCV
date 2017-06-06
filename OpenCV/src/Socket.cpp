#include "../include/Socket.h"

#include <stdio.h>

Socket::Socket(int port_num)
{
    this->port_num = port_num;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    ///AF_INET         IP versão 4
    ///SOCK_STREAM     Orientado a TCP
    ///0               Protocolo

    if(socket_desc >= 0)
        printf("Socket n# %d criado com sucesso. \n", socket_desc);
    if(socket_desc == -1)
        printf("Não foi possível criar o socket. \n");

}
void Socket::encerrar(){
	/////////////////////////////////////////////////////////
    //////////////////       CLOSE     //////////////////////
    //////////////////////////////////////////////////////////

 	int status_close = close(socket_desc);
    //socket_desc     Descrição do Socket

    if(status_close == 0)
        printf("Socket fechado com sucesso.\n");
    if(status_close == -1)
        printf("Erro no encerramento do socket. \n");

}

int Socket::enviar(const char mensagem[], int tam) {


	//////////////////////////////////////////////////////////
    ///////////////////       SEND      //////////////////////
    //////////////////////////////////////////////////////////

    //char retorno[] = "Fim do recebimento!";
    //retorno[19] = 'a';

    int status_send = send(socket_desc,mensagem,tam,0);
    ///socket_desc     Descrição do Socket
    ///msg             const void[], Mensagem a ser transmitida
    ///msgLen          int, tamanho da mensagem em bytes a ser transmitida
    ///flags           int, opções especiais, valor padrão 0

    if(status_send >= 0)
        printf("Recv com sucesso.Número de bytes transmitidos: %d.\n", status_send);
    if(status_send == -1)
        printf("Erro de SEND. \n");

    return status_send;//send(socket_desc, mensagem, tam, 0);

}
int Socket::receber(char mensagem[]) {

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













