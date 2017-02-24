#include<stdio.h>
#include<unistd.h>
/*
int main()
{
	pid_t fpid;
	int count = 0;

	fpid = fork();

	if(fpid < 0)
	{
		printf("error");
	}

	else if(fpid == 0)
	{
		count++;
		printf("I'm the son of my dad,\n,getpid = %d\n, getppid = %d\n", getpid(), getppid());

	}

	else
	{
		count++;
		printf("I'm the dad of my son,\n, getpid = %d\n,getppid = %d\n", getpid(), getppid());
	}
	printf("count = %d\n", count);
	return 0;
}

*/

/*
int main()
{
	int i = 0;
	pid_t fpid = 0;

	printf("i son/pa ppid pid fpid\n");

	for(i = 0; i < 2; i++)
	{	
		fpid = fork();

		if(fpid)
		{
			printf("%d parent %4d %4d %4d\n", i, getppid(), getpid, fpid);
		}
		else
		{
			printf("%d son %4d %4d %4d\n", i, getppid(), getpid(), fpid);
		}
	}

	return 0;
}
*/

#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	if(fork() == 0)
	{
		printf("a\n, getpid = %d\n", getpid());
	}
	else
	{
		printf("b\n, getpid =%d\n", getpid());
		printf("waitpid = %d\n",waitpid(-1, NULL, 0));
	}
	printf("getpid = %d\n", getpid());
	printf("c\n");
	exit(0);
}
