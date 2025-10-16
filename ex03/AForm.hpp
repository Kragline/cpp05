#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	bool				_isSigned;
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm	&operator=(const AForm &other);

	bool		getIsSigned() const ;
	std::string	getName() const ;
	int		 	getGradeToSign() const ;
	int		 	getGradeToExecute() const ;

	void			beSigned(const Bureaucrat &crat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSigned : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &obj);
