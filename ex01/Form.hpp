#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	bool				_isSigned;
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	~Form();

	Form	&operator=(const Form &other);

	bool		getIsSigned() const ;
	std::string	getName() const ;
	int		 	getGradeToSign() const ;
	int		 	getGradeToExecute() const ;

	void		beSigned(const Bureaucrat &crat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

	class FormAlreadySigned : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const Form &obj);
