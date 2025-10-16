#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Intern Creation ---" << std::endl;
	Intern	someRandomIntern;

	Bureaucrat	boss("Boss", 1);
	Bureaucrat	worker("Worker", 70);

	std::cout << "\n--- Form Creation ---" << std::endl;
	AForm	*form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
	AForm	*form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm	*form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
	AForm	*form4 = someRandomIntern.makeForm("unknown form", "Target");

	if (form1)
	{
		std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
		boss.signForm(*form1);
		boss.executeForm(*form1);
	}

	if (form2)
	{
		std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
		worker.signForm(*form2);
		worker.executeForm(*form2);
	}

	if (form3)
	{
		std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
		boss.signForm(*form3);
		boss.executeForm(*form3);
	}

	if (!form4)
		std::cout << "\n-- Invalid Form (NULL returned) --" << std::endl;

	std::cout << "\n--- Cleaning Up ---" << std::endl;
	delete form1;
	delete form2;
	delete form3;

	return (0);
}
