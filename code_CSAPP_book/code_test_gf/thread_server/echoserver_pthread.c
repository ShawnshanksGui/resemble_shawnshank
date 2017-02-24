#include "csapp.h"

void echo(int connfd);
void *thread(void *vargp);


int main(int argc, char **argv)
{
	int listenfd = 0;
	int *connfdp = NULL;
	int port = 0;

	struct sockaddr_in clientaddr;
	pthread_t tid;

	if(argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);

	listenfd = Open_listenfd(port);
	while(1)
	{
		connfd = Malloc(sizeof(int));
		*connfdp = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		Pthread_create(&tid, NULL, thread, connfdp);
	}
}

void *thread(void *vargp)
{
	int connfd = *((int *)vargp);
	Pthread_detach(pthread_self()):
	Free(vargp);
	echo(confd);
	Close(connfd);
	return NULL;
}

