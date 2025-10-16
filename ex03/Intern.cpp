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

AForm	*Intern::makeShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePardon(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget) const
{
	AFormPair	pairs[] = {
		{ "shrubbery creation", &Intern::makeShrubbery },
		{ "robotomy request", &Intern::makeRobotomy },
		{ "presidential pardon", &Intern::makePardon }
	};

	for (int i = 0; i < 3; i++)
	{
		if (pairs[i].name == formName)
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return ((this->*pairs[i].creatorMethod)(formTarget));
		}
	}

	std::cout << "Intern doesn't know anything about " << formName << "!" << std::endl;
	return (NULL);
}
