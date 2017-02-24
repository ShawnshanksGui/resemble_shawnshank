#include <iostream>

int main()
{
	int num_a = 1.0;
	int &ref_a = num_a;
	
	std::cout << ref_a << " " << num_a << std::endl;
	
	return 0;

}
