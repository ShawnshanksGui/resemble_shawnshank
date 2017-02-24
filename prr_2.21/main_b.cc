#include <iostream>
#include <cstdlib>
int main()
{
	int i = 20, *p = &i, &ref_a = i;
	auto ref_b = i;
	std::cout << &i << " " << p << " " << &ref_a 
	<< " " << &ref_b << std::endl;

	return 0;
}
