/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:52 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:11:36 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

typedef unsigned long usize;

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

void Bureaucrat::gradeFilter(usize grade) const {
	if (grade < Bureaucrat::MAX) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > Bureaucrat::MIN) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat() : name("(None)"), grade(Bureaucrat::MIN) {}
Bureaucrat::Bureaucrat(const Bureaucrat &rhs) { *this = rhs; }
Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(Bureaucrat::MIN) {}
Bureaucrat::Bureaucrat(const std::string &name, usize grade) : name(name) {
	Bureaucrat::gradeFilter(grade);
	this->grade = grade;
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this == &rhs) {
		return *this;
	}
	Bureaucrat::gradeFilter(rhs.grade);
	const_cast<std::string &>(name) = rhs.name;
	grade = rhs.grade;
	return *this;
}

const std::string &Bureaucrat::getName() const { return name; }
usize Bureaucrat::getGrade() const { return grade; }
void Bureaucrat::upGrade(usize grade) {
	Bureaucrat::gradeFilter(this->grade - grade);
	this->grade -= grade;
}
void Bureaucrat::downGrade(usize grade) {
	Bureaucrat::gradeFilter(this->grade + grade);
	this->grade += grade;
}
void Bureaucrat::signForm(AForm &rhs) {
	try {
		rhs.beSigned(*this);
		std::cout << this->getName() << " signed " << rhs.getName() << '\n';
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn’t sign "
			<< rhs.getName() << " because " << e.what() << '\n';
	}
}
void Bureaucrat::executeForm(const AForm& rhs) {
	try {
		rhs.execute(*this);
		std::cout << this->getName() << " executed " << rhs.getName() << '\n';
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn’t execute "
			<< rhs.getName() << " because " << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs) {
	return os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
}

