#include <stdio.h>


/* Create a reliable, stream socket using TCP */
if ((clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	DieWithError("socket() failed");



struct sockaddr_in echoServAddr;

echoServAddr.sin_family = AF_INET;
echoServAddr.sin_addr.s_addr = inet_addr(echoservIP);
echoServAddr.sin_port = htons(echoServPort);
/* Internet address family */
/* Server IP address*/
/* Server port */
if (connect(clientSock, (struct sockaddr *) &echoServAddr,
sizeof(echoServAddr)) < 0)
DieWithError("connect() failed");






















close(clientSock);