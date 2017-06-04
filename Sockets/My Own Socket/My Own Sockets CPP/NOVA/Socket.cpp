#include "Socket.h"

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

int Socket::enviar(char mensagem[], int tam) {
    return send(socket_desc, mensagem, tam, 0);

}
int Socket::receber(char * mensagem) {
    return recv(socket_desc, mensagem, TMAX, 0);
}













