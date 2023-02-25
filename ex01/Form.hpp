/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 12:05:43 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#define MIN 150
#define MAX 1

class Bureaucrat;
class Form {
	const std::string name;
	const int signRequiredGrade;
	const int execRequiredGrade;
	bool isSigned;

	void gradeFilter(int grade) const;

public:
	Form();
	Form(const Form& rhs);
	Form(const std::string& name, int srg, int erg);
	virtual ~Form();
	virtual Form& operator=(const Form& rhs);

	virtual const std::string& getName() const;
	virtual const int& getSignReqGrad() const;
	virtual const int& getExecReqGrad() const;
	virtual const bool& getIsSigned() const;
	virtual void beSigned(const Bureaucrat& rhs);

protected:
	class GradeTooHighException : public std::exception {
		public: const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public: const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif
