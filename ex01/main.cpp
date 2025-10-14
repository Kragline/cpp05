#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form f0;
		std::cout << f0 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form f1("Passport", 50, 30);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form f2("TopSecret", 0, 30);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (grade too high for sign): " << e.what() << std::endl;
	}

	try
	{
		Form f3("TopSecret", 30, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (grade too high for execute): " << e.what() << std::endl;
	}

	try
	{
		Form f4("LowClearance", 151, 30);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (grade too low for sign): " << e.what() << std::endl;
	}

	try
	{
		Form f5("LowClearance", 30, 151);
	} catch (std::exception &e) {
		std::cout << "Exception (grade too low for execute): " << e.what() << std::endl;
	}

	{
		Bureaucrat b1("Alice", 40);
		Form f6("Contract", 50, 30);
		b1.signForm(f6);
	}

	{
		Bureaucrat b2("Bob", 100);
		Form f7("Agreement", 50, 30);
		b2.signForm(f7);
	}

	{
		Bureaucrat b3("Charlie", 10);
		Form f8("Permit", 20, 10);
		b3.signForm(f8);
		b3.signForm(f8);
	}

	return (0);
}
