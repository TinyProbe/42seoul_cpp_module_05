/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 12:05:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

typedef unsigned long usize;

const char *Form::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

void Form::gradeFilter(usize grade) const {
	if (grade < Form::MAX) {
		throw Form::GradeTooHighException();
	} else if (grade > Form::MIN) {
		throw Form::GradeTooLowException();
	}
}

Form::Form() :
	name("(None)"),
	signRequiredGrade(Form::MAX),
	execRequiredGrade(Form::MAX),
	sign() {}
Form::Form(const Form &rhs) :
	name(),
	signRequiredGrade(),
	execRequiredGrade(),
	sign()
{
	*this = rhs;
}
Form::Form(const std::string &name, usize srg, usize erg) :
	name(name),
	signRequiredGrade(srg),
	execRequiredGrade(erg),
	sign()
{
	Form::gradeFilter(srg);
	Form::gradeFilter(erg);
}
Form::~Form() {}
Form &Form::operator=(const Form &rhs) {
	if (this == &rhs) {
		return *this;
	}
	Form::gradeFilter(rhs.signRequiredGrade);
	Form::gradeFilter(rhs.execRequiredGrade);
	const_cast<std::string &>(name) = rhs.name;
	const_cast<usize &>(signRequiredGrade) = rhs.signRequiredGrade;
	const_cast<usize &>(execRequiredGrade) = rhs.execRequiredGrade;
	sign = rhs.sign;
	return *this;
}

const std::string &Form::getName() const { return name; }
usize Form::getSignReqGrad() const { return signRequiredGrade; }
usize Form::getExecReqGrad() const { return execRequiredGrade; }
bool Form::getSign() const { return sign; }
void Form::beSigned(const Bureaucrat &rhs) {
	if (rhs.getGrade() <= signRequiredGrade) {
		sign = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const Form &rhs) {
	return os << rhs.getName()
		<< " form's signRequiredGrade " << rhs.getSignReqGrad()
		<< ", execRequiredGrade " << rhs.getExecReqGrad()
		<< ", sign " << rhs.getSign();
}

