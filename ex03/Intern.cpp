#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern was created." << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern was copied." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern was destroyed." << std::endl;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget) const
{
	AForm	*aForm = NULL;

	if (formName == "shrubbery creation")
		aForm = new ShrubberyCreationForm(formTarget);
	else if (formName == "robotomy request")
		aForm = new RobotomyRequestForm(formTarget);
	else if (formName == "presidential pardon")
		aForm = new PresidentialPardonForm(formTarget);
		
	if (aForm)
		std::cout << "Intern creates " << formName << " form!" << std::endl;
	else
		std::cout << "Intern doesn't know anything about " << formName << "!" << std::endl;
	return (aForm);
}
