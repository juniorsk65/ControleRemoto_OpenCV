#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include "Socket.h"
#include <string>
#include <iostream>
//using namespace std;

class SocketClient : public Socket
{
    public:
        SocketClient(){};
        SocketClient(int porta, std::string ipServer);
        virtual ~SocketClient(){};
        void conectar();

    protected:
        std::string ipServer;
    private:
};

#endif // SOCKETCLIENT_H
