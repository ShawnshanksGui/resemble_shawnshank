#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

#define DEF_MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH

int main()
{
	int fd = 0;
	char c = '\0';
	int count = 0;

	//fd =open("hello.txt", O_RDWR | O_CREAT, DEF_MODE);	
	//write(fd, stdout, 5);
	//sprintf(stdin, );
//	printf("hello,%d\n", fd);
	
	while(count = read(STDIN_FILENO, &c, 1) != 0)
	{
		printf("\n%d\n", count);
		write(STDOUT_FILENO, &c, 1);
	}

	exit(0);

	return 0;
}
