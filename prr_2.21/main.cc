#include <iostream>

int main( )
{
	int i = 1;
	int* ptr = &i;
	std::cout << *ptr << std::endl;

	return 0;
}
