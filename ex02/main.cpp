#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat	highRank("Arman", 1);
    Bureaucrat	lowRank("LowGuy", 150);

    // ShrubberyCreationForm tests
    std::cout << "\n--- ShrubberyCreationForm Tests ---\n" << std::endl;
	{
		ShrubberyCreationForm	shrub("Garden");
		highRank.signForm(shrub);
		highRank.executeForm(shrub);
	}
	{
		ShrubberyCreationForm	shrubFail("FailGarden");
		lowRank.signForm(shrubFail);
		lowRank.executeForm(shrubFail);
	}

    // RobotomyRequestForm tests
    std::cout << "\n--- RobotomyRequestForm Tests ---\n" << std::endl;
	{
		RobotomyRequestForm robot("Bender");
		highRank.signForm(robot);
		highRank.executeForm(robot);
	}
	{
		RobotomyRequestForm robotFail("FailBot");
		lowRank.signForm(robotFail);
		lowRank.executeForm(robotFail);
	}

    // PresidentialPardonForm tests
    std::cout << "\n--- PresidentialPardonForm Tests ---\n" << std::endl;
	{
		PresidentialPardonForm pardon("Alice");
		highRank.signForm(pardon);
		highRank.executeForm(pardon);
	}
	{
		PresidentialPardonForm pardonFail("Bob");
		lowRank.signForm(pardonFail);
		lowRank.executeForm(pardonFail);
	}
    return (0);
}
