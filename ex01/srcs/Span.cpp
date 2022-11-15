# include "../class/Span.hpp"

Span::Span(): _size(0), _count(0) 
{
	this->_array.resize(0);
	/* std::cout << "Span Constructor by default called" << std::endl; */
}

Span::Span(unsigned int size): _size(size), _count(0) 
{
	this->_array.resize(this->_size);
	/* std::cout << "Span Constructor overload called" << std::endl; */
}

Span::~Span() 
{
	/* std::cout << "Span Destructor called" << std::endl; */
}

Span::Span(Span const& src): _size(src._size), _count(src._count) 
{
	this->_array.resize(this->_size);
	for (unsigned int i = 0; i < src._size; i++)
		this->_array[i] = src._array[i];
	/* std::cout << "Span Constructor by copy called" << std::endl; */
}

Span & Span::operator=(Span const& src) 
{
	this->_size = src._size;
	this->_count = src._count;
	if (this->_array.empty() == 0)
		this->_array.clear();
	this->_array.resize(this->_size);
	for (unsigned int i = 0; i < src._size; i++)
		this->_array[i] = src._array[i];
	/* std::cout << "Span Constructor by assignement call" << std::endl; */
	return (*this);
}

//Throw
const char* Span::TooManyElement::what() const throw() 
{
	return ("\e[91mArray full\e[39m");
}

const char* Span::NotEnoughNumber::what() const throw() 
{
	return ("\e[91mLacking numbers to find a span\e[39m");
}

void	Span::addNumber(int nb) 
{
	if (this->_count >= this->_size)
		throw TooManyElement();
	this->_array[this->_count] = nb;
	this->_count++;
	std::cout << "Number " << nb << " added" << std::endl;
}

int		Span::shortestSpan() const 
{
	if (this->_count == 0 || this->_count == 1)
		throw NotEnoughNumber();

	Span	tmp(*this);
	std::sort(tmp._array.begin(), tmp._array.end());
	
	int		ret = tmp._array[1] - tmp._array[0];
	for (unsigned int i = 0; i < tmp._count; i++)
	{
		if (i + 1 < tmp._count)
			if (tmp._array[i + 1] - tmp._array[i] < ret)
				ret = tmp._array[i + 1] - tmp._array[i];
	}
	return (ret);
}

int		Span::longestSpan() const 
{
	if (this->_count == 0 || this->_count == 1)
		throw NotEnoughNumber();

	Span	tmp(*this);
	unsigned int	i;
	
	std::sort(tmp._array.begin(), tmp._array.end());
	for (i = 0; i < tmp._count;)
		i++;
	int ret = tmp._array[i - 1];
	return (ret - tmp._array[0]);
}

void	Span::addNumberRange(int size) 
{
	for (int i = 0; i < size; i++)
	{
		if (this->_count >= this->_size)
			throw TooManyElement();
		this->_array[i] = i;
		this->_count++;
	}
}

void	Span::addList(std::vector<int>	tab) 
{
	int size = tab.size();
	if (size + this->_count > this->_size)
		throw TooManyElement();
	
	for(int i = 0; i < size; i++)
	{
		this->_array[this->_count] = tab[i];
		this->_count++;
	}
}

void	Span::Display(Span const& src)
{
	int size = src._size;
	for (int i = 0; i < size; i++)
		std::cout << src._array[i] << std::endl;
}