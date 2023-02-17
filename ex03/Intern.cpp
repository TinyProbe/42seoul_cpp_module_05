/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:20:19 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 19:33:37 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& rhs) { *this = rhs; }
Intern::~Intern() {}
Intern& Intern::operator=(const Intern& rhs) {
	if (this == &rhs) {
		return *this;
	}
	return *this;
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const {
	AForm* obj = nullptr;
	obj = (form == "shrubbery creation" ? new ShrubberyCreationForm(target) : obj);
	obj = (form == "robotomy request" ? new RobotomyRequestForm(target) : obj);
	obj = (form == "presidential parden" ? new PresidentialPardonForm(target) : obj);
	if (obj == nullptr) {
		std::cout << "Doesn't exist like " << form << " form\n";
	}
	return obj;
}
