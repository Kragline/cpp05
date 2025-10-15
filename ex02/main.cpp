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
    try
	{
        ShrubberyCreationForm	shrub("Garden");
        highRank.signForm(shrub);
        shrub.execute(highRank);
    }
	catch (std::exception &e)
	{
        std::cout << "ShrubberyCreationForm Exception: " << e.what() << std::endl;
    }
    try
	{
        ShrubberyCreationForm	shrubFail("FailGarden");
        lowRank.signForm(shrubFail);
        shrubFail.execute(lowRank);
    }
	catch (std::exception &e)
	{
        std::cout << "ShrubberyCreationForm Exception (low rank): " << e.what() << std::endl;
    }

    // RobotomyRequestForm tests
    std::cout << "\n--- RobotomyRequestForm Tests ---\n" << std::endl;
    try
	{
        RobotomyRequestForm robot("Bender");
        highRank.signForm(robot);
        robot.execute(highRank);
    }
	catch (std::exception &e)
	{
        std::cout << "RobotomyRequestForm Exception: " << e.what() << std::endl;
    }

    try
	{
        RobotomyRequestForm robotFail("FailBot");
        lowRank.signForm(robotFail);
        robotFail.execute(lowRank);
    }
	catch (std::exception &e)
	{
        std::cout << "RobotomyRequestForm Exception (low rank): " << e.what() << std::endl;
    }

    // PresidentialPardonForm tests
    std::cout << "\n--- PresidentialPardonForm Tests ---\n" << std::endl;
    try
	{
        PresidentialPardonForm pardon("Alice");
        highRank.signForm(pardon);
        pardon.execute(highRank);
    }
	catch (std::exception &e)
	{
        std::cout << "PresidentialPardonForm Exception: " << e.what() << std::endl;
    }
    try
	{
        PresidentialPardonForm pardonFail("Bob");
        lowRank.signForm(pardonFail);
        pardonFail.execute(lowRank);
    }
	catch (std::exception &e)
	{
        std::cout << "PresidentialPardonForm Exception (low rank): " << e.what() << std::endl;
    }

    return (0);
}
