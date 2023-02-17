/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 04:22:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const std::string AForm::GradeTooHighException("AForm : Grade too high");
const std::string AForm::GradeTooLowException("AForm : Grade too low");

void AForm::gradeFilter(int grade) {
	if (grade < MAX) {
		throw std::invalid_argument(AForm::GradeTooHighException);
	} else if (grade > MIN) {
		throw std::invalid_argument(AForm::GradeTooLowException);
	}
}

AForm::AForm() :
	name("(None)"),
	signRequiredGrade(MAX),
	execRequiredGrade(MAX),
	isSigned() {}
AForm::AForm(const AForm& rhs) :
	name(),
	signRequiredGrade(),
	execRequiredGrade(),
	isSigned()
{
	*this = rhs;
}
AForm::AForm(const std::string& name, int srg, int erg) :
	name(name),
	signRequiredGrade(srg),
	execRequiredGrade(erg),
	isSigned()
{
	AForm::gradeFilter(srg);
	AForm::gradeFilter(erg);
}
AForm::~AForm() {}
AForm& AForm::operator=(const AForm& rhs) {
	if (this == &rhs) {
		return *this;
	}
	AForm::gradeFilter(rhs.signRequiredGrade);
	AForm::gradeFilter(rhs.execRequiredGrade);
	const_cast<std::string&>(this->name) = rhs.name;
	const_cast<int&>(this->signRequiredGrade) = rhs.signRequiredGrade;
	const_cast<int&>(this->execRequiredGrade) = rhs.execRequiredGrade;
	this->isSigned = rhs.isSigned;
	return *this;
}

const std::string& AForm::getName() const { return this->name; }
const int& AForm::getSignReqGrad() const { return this->signRequiredGrade; }
const int& AForm::getExecReqGrad() const { return this->execRequiredGrade; }
const bool& AForm::getIsSigned() const { return this->isSigned; }
void AForm::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() <= this->signRequiredGrade) {
		this->isSigned = true;
	} else {
		throw std::runtime_error(AForm::GradeTooLowException);
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	return os << rhs.getName()
		<< " form's signRequiredGrade " << rhs.getSignReqGrad()
		<< ", execRequiredGrade " << rhs.getExecReqGrad()
		<< ", isSigned " << rhs.getIsSigned();
}
