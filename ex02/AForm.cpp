/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 10:07:19 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

typedef unsigned long usize;

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }

void AForm::gradeFilter(usize grade) const {
	if (grade < AForm::MAX) {
		throw AForm::GradeTooHighException();
	} else if (grade > AForm::MIN) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm() :
	name("(None)"),
	signRequiredGrade(AForm::MAX),
	execRequiredGrade(AForm::MAX),
	sign() {}
AForm::AForm(const AForm &rhs) :
	name(),
	signRequiredGrade(),
	execRequiredGrade(),
	sign()
{
	*this = rhs;
}
AForm::AForm(const std::string &name, usize srg, usize erg) :
	name(name),
	signRequiredGrade(srg),
	execRequiredGrade(erg),
	sign()
{
	AForm::gradeFilter(srg);
	AForm::gradeFilter(erg);
}
AForm::~AForm() {}
AForm &AForm::operator=(const AForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	AForm::gradeFilter(rhs.signRequiredGrade);
	AForm::gradeFilter(rhs.execRequiredGrade);
	const_cast<std::string &>(name) = rhs.name;
	const_cast<usize &>(signRequiredGrade) = rhs.signRequiredGrade;
	const_cast<usize &>(execRequiredGrade) = rhs.execRequiredGrade;
	sign = rhs.sign;
	return *this;
}

const std::string &AForm::getName() const { return name; }
usize AForm::getSignReqGrad() const { return signRequiredGrade; }
usize AForm::getExecReqGrad() const { return execRequiredGrade; }
bool AForm::getSign() const { return sign; }
void AForm::beSigned(const Bureaucrat &rhs) {
	if (rhs.getGrade() <= signRequiredGrade) {
		sign = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &rhs) {
	return os << rhs.getName()
		<< " form's signRequiredGrade " << rhs.getSignReqGrad()
		<< ", execRequiredGrade " << rhs.getExecReqGrad()
		<< ", sign " << rhs.getSign();
}

