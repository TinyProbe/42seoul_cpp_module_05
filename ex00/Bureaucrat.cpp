/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:52 by tkong             #+#    #+#             */
/*   Updated: 2023/02/16 21:30:29 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string Bureaucrat::GradeTooHighException("Grade too high");
const std::string Bureaucrat::GradeTooLowException("Grade too low");

void Bureaucrat::gradeFilter(int grade) {
	if (grade < MAX) {
		throw std::invalid_argument(Bureaucrat::GradeTooHighException);
	} else if (grade > MIN) {
		throw std::invalid_argument(Bureaucrat::GradeTooLowException);
	}
}

Bureaucrat::Bureaucrat() : name("(None)"), grade(MIN) {}
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) {
	*this = rhs;
}
Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(MIN) {}
Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name) {
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

const std::string& Bureaucrat::getName() const {
	return this->name;
}
const int& Bureaucrat::getGrade() const {
	return this->grade;
}
void Bureaucrat::upGrade(int grade) {
	Bureaucrat::gradeFilter(this->grade - grade);
	this->grade -= grade;
}
void Bureaucrat::downGrade(int grade) {
	Bureaucrat::gradeFilter(this->grade + grade);
	this->grade += grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	return os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
}
