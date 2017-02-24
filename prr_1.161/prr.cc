#include <iostream>

int main()
{
	int currVAL = 0, val = 0;
						
	if(std::cin >> currVAL)
	{
		int cnt = 1;
				
		while(std::cin >> val)
		{
			if(val == currVAL)
			{
				cnt ++;
			}
			else
			{
				std::cout << currVAL << "occur" << cnt << "times" << std::endl;
				cnt = 1;
				currVAL = val;
			}
		}
		
		std::cout << currVAL << "occur" << cnt << "times" << std::endl;  // print the number of last numerical symbol 
	}	 
	
	return 0;
}


