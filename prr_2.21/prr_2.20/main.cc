#include <iostream>

int main( )
{
	int num_a = 10;

	int *ptr_a = &num_a;

	*ptr_a = *ptr_a * *ptr_a;

	std::cout << *ptr_a << std::endl;
	
	return 0;
}
