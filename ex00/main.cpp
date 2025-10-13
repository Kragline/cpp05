#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat	b0;
		std::cout << b0 << std::endl;
		b0.incrementGrade();
		std::cout << b0 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b1("Alice", 42);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b2("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (grade too high): " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b3("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (grade too low): " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b4("Diana", 1);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (increment too high): " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b5("Eve", 150);
		std::cout << b5 << std::endl;
		b5.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (decrement too low): " << e.what() << std::endl;
	}

	return (0);
}
