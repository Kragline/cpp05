#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
private:
	typedef AForm *(Intern::*formCreator)(const std::string &) const ;

	struct AFormPair
	{
		std::string	name;
		formCreator	creatorMethod;
	};
	
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern	&operator=(const Intern &other);

	AForm	*makeForm(std::string formName, std::string formTarget) const ;
	AForm	*makeShrubbery(const std::string &target) const ;
	AForm	*makeRobotomy(const std::string &target) const ;
	AForm	*makePardon(const std::string &target) const ;
};
