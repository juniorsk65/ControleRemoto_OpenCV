#include <stdio.h>


if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	DieWithError("socket() failed");

struct sockaddr_in echoServAddr;
echoServAddr.sin_family = AF_INET;
echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
echoServAddr.sin_port = htons(echoServPort);
/* Internet address family */
/* Any incoming interface */

/* Local port */
if (bind(servSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
	DieWithError("bind() failed");

/* Mark the socket so it will listen for incoming connections */
if (listen(servSock, MAXPENDING) < 0)
	DieWithError("listen() failed");

for (;;) /* Run forever */
{
clntLen = sizeof(echoClntAddr);
if ((clientSock=accept(servSock,(struct sockaddr *)&echoClntAddr,&clntLen))<0)
	DieWithError("accept() failed");
}

























close(clientSock);