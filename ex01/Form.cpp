/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 03:32:38 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const std::string Form::GradeTooHighException("Form : Grade too high");
const std::string Form::GradeTooLowException("Form : Grade too low");

void Form::gradeFilter(int grade) {
	if (grade < MAX) {
		throw std::invalid_argument(Form::GradeTooHighException);
	} else if (grade > MIN) {
		throw std::invalid_argument(Form::GradeTooLowException);
	}
}

Form::Form() :
	name("(None)"),
	signRequiredGrade(MAX),
	execRequiredGrade(MAX),
	isSigned() {}
Form::Form(const Form& rhs) :
	name(),
	signRequiredGrade(),
	execRequiredGrade(),
	isSigned()
{
	*this = rhs;
}
Form::Form(const std::string& name, int srg, int erg) :
	name(name),
	signRequiredGrade(srg),
	execRequiredGrade(erg),
	isSigned()
{
	Form::gradeFilter(srg);
	Form::gradeFilter(erg);
}
Form::~Form() {}
Form& Form::operator=(const Form& rhs) {
	if (this == &rhs) {
		return *this;
	}
	Form::gradeFilter(rhs.signRequiredGrade);
	Form::gradeFilter(rhs.execRequiredGrade);
	const_cast<std::string&>(this->name) = rhs.name;
	const_cast<int&>(this->signRequiredGrade) = rhs.signRequiredGrade;
	const_cast<int&>(this->execRequiredGrade) = rhs.execRequiredGrade;
	this->isSigned = rhs.isSigned;
	return *this;
}

const std::string& Form::getName() const { return this->name; }
const int& Form::getSignReqGrad() const { return this->signRequiredGrade; }
const int& Form::getExecReqGrad() const { return this->execRequiredGrade; }
const bool& Form::getIsSigned() const { return this->isSigned; }
void Form::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() <= this->signRequiredGrade) {
		this->isSigned = true;
	} else {
		throw std::runtime_error(Form::GradeTooLowException);
	}
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	return os << rhs.getName()
		<< " form's signRequiredGrade " << rhs.getSignReqGrad()
		<< ", execRequiredGrade " << rhs.getExecReqGrad()
		<< ", isSigned " << rhs.getIsSigned();
}
