/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:52 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 12:05:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

void Bureaucrat::gradeFilter(int grade) const {
	if (grade < MAX) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > MIN) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat() : name("(None)"), grade(MIN) {}
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) { *this = rhs; }
Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(MIN) {}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	Bureaucrat::gradeFilter(grade);
	this->grade = grade;
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this == &rhs) {
		return *this;
	}
	Bureaucrat::gradeFilter(rhs.grade);
	const_cast<std::string&>(this->name) = rhs.name;
	this->grade = rhs.grade;
	return *this;
}

const std::string& Bureaucrat::getName() const { return this->name; }
const int& Bureaucrat::getGrade() const { return this->grade; }
void Bureaucrat::upGrade(int grade) {
	if (grade < 0) {
		throw std::invalid_argument("invalid_argument");
	}
	Bureaucrat::gradeFilter(this->grade - grade);
	this->grade -= grade;
}
void Bureaucrat::downGrade(int grade) {
	if (grade < 0) {
		throw std::invalid_argument("invalid_argument");
	}
	Bureaucrat::gradeFilter(this->grade + grade);
	this->grade += grade;
}
void Bureaucrat::signForm(Form& rhs) {
	try {
		rhs.beSigned(*this);
		std::cout << this->getName() << " signed " << rhs.getName() << '\n';
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn’t sign "
			<< rhs.getName() << " because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	return os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
}
