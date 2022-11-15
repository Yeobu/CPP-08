# include "../class/easyfind.hpp"

int main( void )
{
	std::vector<int>	arr(7);
	arr[0] = 42;
	arr[1] = 4242;
	arr[2] = 21;
	arr[3] = 84;
	arr[4] = 4;
	arr[5] = 2;
	Display(arr, arr.size());
	
	std::cout << "\e[1;4;93mEASYFIND\e[0;39m" << std::endl;
	try
	{
		std::cout << easyfind(arr, 42) << std::endl;
		std::cout << easyfind(arr, 4) << std::endl;
		std::cout << easyfind(arr, 0) << std::endl;
		std::cout << easyfind(arr, 7) << std::endl;
	}
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }
	return (0);
}