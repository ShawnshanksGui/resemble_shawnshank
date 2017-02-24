#include "caspp.h"
#include "sbuf.h"

#define NTHREADS 4
#define SBUFSIZE 16

void echo_nt(int connfd);
void *thread(void *vargp);

sbuf_t sbuf;

int main(int argc, char **argv)
{
	int i= 0;
	int listenfd = 0;
	int connfd = 0;
	int port = 0;

	socklen_t clientlen = sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;
	pthread_t tid;

	if(argc != 2)
	{
		fprintf(stderr, "usage:%s <port>\n", argv[0]);
		exit(0);
	}
	
	port = atoi(argv[1]);
	sbuf_init(&sbuf, SBUFSIZE);
	listennfd = open_listenfd(port);

	for(i = 0; i < NTHREADS; i++)
	{
		pthread_create(&tid, NULL, thread, NULL);
	}

	while(1)
	{
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		sbuf_insert(&sbuf, connfd);
	}
}

void *thread(void *vargp)
{
	Pthread_detatch(pthread_self());
	while(1)
	{
		int connfd = sbuf_remove(&sbuf);
		echo_cnt(connfd);
		Close(connfd);
	}
}


