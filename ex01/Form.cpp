#include "Form.hpp"

Form::Form() : _isSigned(false), _name("Loan Document"), _gradeToSign(110), _gradeToExecute(105)
{
	std::cout << "Default Form Loan Document was created." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _isSigned(false), _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " was created." << std::endl;
}

Form::Form(const Form &other) : _isSigned(other.getIsSigned()), _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
	std::cout << "Form " << _name << " was copied." << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " was destroyed." << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other.getIsSigned();
	return (*this);
}

bool	Form::getIsSigned() const { return (_isSigned); }
std::string	Form::getName() const { return (_name); }
int	Form::getGradeToSign() const { return (_gradeToSign); }
int	Form::getGradeToExecute() const { return (_gradeToExecute); }

void	Form::beSigned(const Bureaucrat &crat)
{
	if (_isSigned)
		throw FormAlreadySigned();
	if (crat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &stream, const Form &obj)
{
	stream << "Form /" << obj.getName()
		<< ": status - " << ((obj.getIsSigned()) ? "signed" : "not signed")
		<< ", grade to sign - " << obj.getGradeToSign()
		<< ", grade to execute - " << obj.getGradeToExecute() << "/";
	return (stream);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*Form::FormAlreadySigned::what() const throw()
{
	return ("Form is already signed!");
}
