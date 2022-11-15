#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <vector>
# include <iterator>
# include <stdexcept>

class Span
{
	private:
		std::vector<int>	_array;
		unsigned int		_size;
		unsigned int		_count;
		
		Span();
	
	public:
		Span(unsigned int len);
		virtual ~Span();
		Span(Span const& src);
		Span & operator=(Span const& src);
		
		//Throw
		class TooManyElement : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class NotEnoughNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		void	addNumber(int nb);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addNumberRange(int size);
		void	addList(std::vector<int> tab);
		void	Display(Span const& src);
};

#endif