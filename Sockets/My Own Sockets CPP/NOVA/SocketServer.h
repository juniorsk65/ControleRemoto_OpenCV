#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include "Socket.h"


class SocketServer : public Socket
{
    public:
        SocketServer(){};
        SocketServer(int port_num);
        virtual ~SocketServer(){};
        int aceitar();
        int boot();
        int receber(char mensagem[]);
    private:
        struct sockaddr client;

};

#endif // SOCKETSERVER_H
