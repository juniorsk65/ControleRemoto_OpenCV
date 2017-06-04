#ifndef SOCKET_H
#define SOCKET_H

#define TMAX 2000

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h> //inet_addr


class Socket
{
    public:
        Socket(){};
        Socket(int port_num);
        virtual ~Socket(){};
        int enviar(char menssagem[], int tam);
        int receber(char* menssagem);

    protected:
        int socket_desc;
        int port_num;
        struct sockaddr_in server;
        char * message [TMAX];

    private:
};

#endif // SOCKET_H
