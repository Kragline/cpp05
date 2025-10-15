#include "AForm.hpp"

AForm::AForm() : _isSigned(false), _name("Loan Document"), _gradeToSign(110), _gradeToExecute(105)
{
	std::cout << "Default AForm Loan Document was created." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _isSigned(false), _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm " << _name << " was created." << std::endl;
}

AForm::AForm(const AForm &other) : _isSigned(other.getIsSigned()), _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
	std::cout << "AForm " << _name << " was copied." << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " was destroyed." << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other.getIsSigned();
	return (*this);
}

bool	AForm::getIsSigned() const { return (_isSigned); }
std::string	AForm::getName() const { return (_name); }
int	AForm::getGradeToSign() const { return (_gradeToSign); }
int	AForm::getGradeToExecute() const { return (_gradeToExecute); }

void	AForm::beSigned(const Bureaucrat &crat)
{
	if (_isSigned)
		throw FormAlreadySigned();
	if (crat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &stream, const AForm &obj)
{
	stream << "AForm /" << obj.getName()
		<< ": status - " << ((obj.getIsSigned()) ? "signed" : "not signed")
		<< ", grade to sign - " << obj.getGradeToSign()
		<< ", grade to execute - " << obj.getGradeToExecute() << "/";
	return (stream);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*AForm::FormAlreadySigned::what() const throw()
{
	return ("Form is already signed!");
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed yet!");
}
