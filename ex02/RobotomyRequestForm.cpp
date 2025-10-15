#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("galactic_empire")
{
	std::cout << "Default RobotomyRequestForm was created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm was created with target " << _target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other._target)
{
	std::cout << "RobotomyRequestForm with target " << _target << " was copied." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm with target " << _target << " was destroyed." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator==(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	// TODO
}
