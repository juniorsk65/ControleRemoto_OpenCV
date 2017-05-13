#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
    int socket_desc;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    //AF_INET         IP version 4
    //SOCK_STREAM     oriented to TCP
    //0               Protocol

    if(socket_desc == -1){
        printf("Could not create socket");

    }

    //////////////////////////////////////////////////////////
    ///////////////////      BIND      ///////////////////////
    //////////////////////////////////////////////////////////

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);

    int status_bind = bind(socket_desc, (struct sockaddr *) &server, 100);

    int status_listen = listen(socket_desc, 2);

    int s = accept(sockit, )


    //accept();
    //recv();
    //send();
    //close();



}
