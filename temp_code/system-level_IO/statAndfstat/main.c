#include "unistd.h"

int main()
{
	struct stat *ptr = NULL; 
	ptr = (struct stat *)malloc(sizeof(struct stat));
	
	stat("hello.txt", ptr);	
	
	return 0;
}
