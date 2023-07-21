/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:51 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 12:03:43 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;
class Bureaucrat {
	typedef unsigned long usize;
	const std::string name;
	usize grade;

	void gradeFilter(usize grade) const;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat(const std::string &name);
	Bureaucrat(const std::string &name, usize grade);
	virtual ~Bureaucrat();
	virtual Bureaucrat &operator=(const Bureaucrat &rhs);

	virtual const std::string &getName() const;
	virtual usize getGrade() const;
	virtual void upGrade(usize grade);
	virtual void downGrade(usize grade);
	virtual void signForm(Form &rhs);

private:
	class GradeTooHighException : public std::exception {
		public: const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public: const char *what() const throw();
	};
	enum Range {
		MIN = 150,
		MAX = 1,
	};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif

