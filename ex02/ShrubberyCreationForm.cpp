#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("galactic_empire")
{
	std::cout << "Default ShrubberyCreationForm was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm was created with target " << _target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other._target)
{
	std::cout << "ShrubberyCreationForm with target " << _target << " was copied." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm with target " << _target << " was destroyed." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator==(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	// TODO
}
