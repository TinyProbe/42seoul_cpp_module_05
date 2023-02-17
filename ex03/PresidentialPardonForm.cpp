/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:01:29 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 08:40:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) :
	AForm(rhs) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm(target, 25, 5) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this == &rhs) {
		return *this;
	}
	*dynamic_cast<AForm*>(this) = *dynamic_cast<const AForm*>(&rhs);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() <= this->getExecReqGrad()) {
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
	} else {
		throw std::runtime_error(AForm::GradeTooLowException);
	}
}
