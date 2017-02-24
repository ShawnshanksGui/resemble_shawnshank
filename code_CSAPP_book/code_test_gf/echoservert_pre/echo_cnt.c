#include<csapp.h>

static int byte_cnt;
static sem_t mutex;

static void init_echo_cnt(void)
{
	Sem_init(&mutex, 0, 1);
	byte_cnt = 0;
}


void echo_cnt(int connfd)
{
	int n;
	char buf[MAXLINE];
	static pthread_once = PTHREAD_ONCE_INIT;

	Pthread_once(&once, init_cnt);
	Rio_readlinitb(&rio, connfd);
	while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
	{
		P(&mutex);
		byte_cnt += n;
		printf("thread %d received %d (%d total) bytes oon fd %d\n",
			  (int) );
	}

}
