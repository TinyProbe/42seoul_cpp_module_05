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

class Bureaucrat;
class Form {
	typedef unsigned long usize;
	const std::string name;
	const usize signRequiredGrade;
	const usize execRequiredGrade;
	bool sign;

	void gradeFilter(usize grade) const;

public:
	Form();
	Form(const Form &rhs);
	Form(const std::string &name, usize srg, usize erg);
	virtual ~Form();
	virtual Form &operator=(const Form &rhs);

	virtual const std::string &getName() const;
	virtual usize getSignReqGrad() const;
	virtual usize getExecReqGrad() const;
	virtual bool getSign() const;
	virtual void beSigned(const Bureaucrat &rhs);

protected:
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

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif

