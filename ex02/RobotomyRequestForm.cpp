/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:00:24 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 08:38:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) :
	AForm(rhs) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm(target, 72, 45) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this == &rhs) {
		return *this;
	}
	*dynamic_cast<AForm*>(this) = *dynamic_cast<const AForm*>(&rhs);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	std::cout << "Some drilling noises ...\n";
	if (executor.getGrade() <= this->getExecReqGrad()) {
		std::cout << this->getName()
			<< " has been robotomized successfully 50% of the time\n";
	} else {
		std::cout << "The robotomy failed\n";
		throw std::runtime_error(AForm::GradeTooLowException);
	}
}
