#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include "Socket.h"
#include <string>
using namespace std;

class SocketClient : public Socket
{
    public:
        SocketClient(){};
        SocketClient(int porta, string ipServer);
        virtual ~SocketClient(){};
        void conectar();

    protected:
        string ipServer;
    private:
};

#endif // SOCKETCLIENT_H
