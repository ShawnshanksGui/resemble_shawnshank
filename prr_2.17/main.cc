#include <iostream>

int main( )
{
	int i, &ri = i;
	i = 5,ri = 10;
	
	int &rk = ri;

	std::cout << i << " " << ri << rk << std::endl;
	
	return 0;
}
