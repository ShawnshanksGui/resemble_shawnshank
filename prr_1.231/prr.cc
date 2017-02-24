#include <iostream>
#include "Sales_item.h"

int main( )
{
	Sales_item total;

	if(std::cin >> total)
	{
		Sales_item tran;

		while(std::cin >> tran)
		{
			if(tran == total)
			{
				total += tran;
			}

			else
			{
				std::cout << total << std::endl;
				total = tran;
			}
		}

		std::cout << total << std::endl;
	}
	
	else
	{
		std::cerr << "NO DATA" << std::endl;
		return -1;
	}
	return 0;
}
