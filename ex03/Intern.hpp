#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern	&operator=(const Intern &other);

	AForm	*makeForm(std::string formName, std::string formTarget) const ;
};
