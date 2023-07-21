/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:00:24 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:37:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <random>

int RobotomyRequestForm::_rand(int mn, int mx) {
    static std::mt19937 gnt((std::random_device())());
    return (std::uniform_int_distribution<int>(mn, mx))(gnt);
}

RobotomyRequestForm::RobotomyRequestForm() :
	AForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) :
	AForm(rhs) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm(target, 72, 45) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	dynamic_cast<AForm &>(*this) = dynamic_cast<const AForm &>(rhs);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
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
	std::cout << "Some drilling noises ...\n";
	std::cout << (_rand(0, 1)
		? getName() + " has been robotomized successfully 50% of the time\n"
		: "The robotomy failed\n");
}

