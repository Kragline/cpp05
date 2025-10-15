#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Gagas"), _grade(100)
{
	std::cout << "Default Bureaucrat Gagas was created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat " << _name << " was copied." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " was destroyed." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const { return (_name); }

int	Bureaucrat::getGrade() const { return (_grade); }

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const AForm::FormAlreadySigned& e)
	{
		std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is less than 1 - too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is greather than 150 - too low!");
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (stream);
}
