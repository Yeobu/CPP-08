#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>

//Throw
class ElementNotFound : public std::exception
{
	public:
		virtual const char* what() const throw() {
				return ("\e[91mElement not found in this array\e[39m");
		}
};

//Templates
template< typename T >
int	easyfind(T cont, int nb) 
{
	int size = cont.size();
	for (int i = 0; i < size; i++)
		if (cont[i] == nb)
			return (i);
	throw ElementNotFound();
	return (0);
}

template< typename T >
void	Display(T tab, int size) 
{
	for (int i = 0; i < size; i++)
		std::cout << "tab[" << i << "] => " << tab[i] << std::endl;
}

#endif