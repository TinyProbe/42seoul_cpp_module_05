/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:01:29 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:37:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) :
	AForm(rhs) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm(target, 25, 5) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	dynamic_cast<AForm &>(*this) = dynamic_cast<const AForm &>(rhs);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	int err = 0;
	err = (!getSign() ? 1 : err);
	err = (executor.getGrade() > getExecReqGrad() ? 2 : err);
	switch (err) {
		case 1: throw std::runtime_error("can't execute about doesn't signed form");
			break;
		case 2: throw AForm::GradeTooLowException();
			break;
		default: break;
	}
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

