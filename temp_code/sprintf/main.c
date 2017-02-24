#include<stdio.h>

int main(int argc, char **argv)
{
	char array[100] = {'\0'};
	char *ptr = array;

	if(argc >=3)
		return 1;
//	sprintf(ptr, argv[0]);
	sprintf(ptr, "we are family ++ %s" ,argv[1]);
//	sprintf(ptr, "guifei", ptr);
	printf("%s\n",ptr);
	
	return 0;
}
