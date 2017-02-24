#include "stdio.h"
#include "csapp.h"
#include "string.h"

int main()
{
	int n = 0;
	rio_t rio;

	char buf[MAXLINE] = "hello,world;hello,guifei";
	char *ptr = buf;
	
	memcpy(ptr,"banana", 6);
	
	return 0;

/*
	Rio_readinitb(&rio, STDIN_FILENO);
	while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
	{
		Rio_writen(STDOUT_FILENO, buf, n);
	}
*/
	

	return 0;
}

/*
ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *bufp = usrbuf;

	while(nleft > 0)
	{
		if((nread = read(fd, bufp, nleft)) < 0)
		{
			if(errno == EINTR)
			{
				nread = 0;
			}
			else
				return -1;
		}
		else if( nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}

	return (n - nleft);
}
*/











