#include <unistd.h>
#define BUFSIZ 100

int main()
{
	char buf[BUFSIZ] = {'\0'};
	int n = 0;

	while((n = read(0, buf, BUFSIZ) > 0))
	{
		write(1, buf, n);
	}

	return 0;
}
