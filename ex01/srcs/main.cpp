# include "../class/Span.hpp"

int main( void )
{
	
	std::cout << std::endl << "\e[1;4;93mMAIN FROM SUBJECT\e[0;39m" << std::endl << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	

	std::cout << std::endl << "\e[1;4;93mMORE\e[0;39m" << std::endl << std::endl;
	{
		std::cout << "\e[96mFull array\e[39m" << std::endl;
		{
			try
			{
				Span	sp = Span(2);
	
				sp.addNumber(0);
				sp.addNumber(1);
				sp.addNumber(2);
				sp.addNumber(3);
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	
		std::cout << std::endl;
		std::cout << "\e[96mEmpty Span\e[39m" << std::endl;
		{
			std::cout << "shortestSpan :" << std::endl;
			{
				try
				{
					Span	sp = Span(0);
	
					sp.shortestSpan();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
	
			std::cout << std::endl;
			std::cout << "longestSpan :" << std::endl;
			{
				try
				{
					Span	sp = Span(0);
	
					sp.longestSpan();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
	
		std::cout << std::endl;
		std::cout << "\e[96mSpan of size 1\e[39m" << std::endl;
		{
			std::cout << "shortestSpan :" << std::endl;
			{
				try
				{
					Span	sp = Span(1);
	
					sp.addNumber(0);
					sp.shortestSpan();
				}
				catch (const std::exception& e)
				{	std::cerr << e.what() << std::endl; }
			}
	
			std::cout << std::endl;
			std::cout << "longestSpan :" << std::endl;
			{
				try
				{
					Span	sp = Span(1);
	
					sp.addNumber(0);
					sp.longestSpan();
				}
				catch (const std::exception& e)
				{	std::cerr << e.what() << std::endl; }
			}
		}
		
		std::cout << std::endl;
		std::cout << "\e[96maddNumberRange\e[39m" << std::endl;
		{
			try
			{
				Span	sp = Span(42000);
			
				sp.addNumberRange(42000);
				std::cout << "shortestSpan" << std::endl;
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan" <<  std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		try
		{
		Span test = Span(10);
		for (int i = 0; i < 1000; i++)
			test.addNumber(std::rand());
		test.Display(test);
		}

		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	return (0);
}