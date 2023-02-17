/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:52 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 09:12:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const std::string Bureaucrat::GradeTooHighException("Bureaucrat : Grade too high");
const std::string Bureaucrat::GradeTooLowException("Bureaucrat : Grade too low");

void Bureaucrat::gradeFilter(int grade) {
	if (grade < MAX) {
		throw std::invalid_argument(Bureaucrat::GradeTooHighException);
	} else if (grade > MIN) {
		throw std::invalid_argument(Bureaucrat::GradeTooLowException);
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
	Bureaucrat::gradeFilter(this->grade - grade);
	this->grade -= grade;
}
void Bureaucrat::downGrade(int grade) {
	Bureaucrat::gradeFilter(this->grade + grade);
	this->grade += grade;
}
void Bureaucrat::signForm(AForm& rhs) {
	try {
		rhs.beSigned(*this);
		std::cout << this->getName() << " signed " << rhs.getName() << '\n';
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn’t sign "
			<< rhs.getName() << " because " << e.what() << '\n';
	}
}
void Bureaucrat::execForm(const AForm& rhs) {
	try {
		rhs.execute(*this);
		std::cout << this->getName() << " executed " << rhs.getName() << '\n';
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn’t execute "
			<< rhs.getName() << " because " << e.what() << '\n';
	} catch (const std::string& what) {
		std::cout << what << '\n';
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	return os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}
