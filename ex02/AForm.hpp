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
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;
class AForm {
	typedef unsigned long usize;
	const std::string name;
	const usize signRequiredGrade;
	const usize execRequiredGrade;
	bool sign;

	void gradeFilter(usize grade) const;

public:
	AForm();
	AForm(const AForm &rhs);
	AForm(const std::string &name, usize srg, usize erg);
	virtual ~AForm();
	virtual AForm &operator=(const AForm &rhs);

	virtual const std::string &getName() const;
	virtual usize getSignReqGrad() const;
	virtual usize getExecReqGrad() const;
	virtual bool getSign() const;
	virtual void beSigned(const Bureaucrat &rhs);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif

