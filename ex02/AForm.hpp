/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 10:59:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#define MIN 150
#define MAX 1

class Bureaucrat;
class AForm {
	const std::string name;
	const int signRequiredGrade;
	const int execRequiredGrade;
	bool isSigned;

	void gradeFilter(int grade) const;

public:
	AForm();
	AForm(const AForm& rhs);
	AForm(const std::string& name, int srg, int erg);
	virtual ~AForm();
	virtual AForm& operator=(const AForm& rhs);

	virtual const std::string& getName() const;
	virtual const int& getSignReqGrad() const;
	virtual const int& getExecReqGrad() const;
	virtual const bool& getIsSigned() const;
	virtual void beSigned(const Bureaucrat& rhs);
	virtual void execute(Bureaucrat const& executor) const = 0;

protected:
	class GradeTooHighException : public std::exception {
		public: const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public: const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
