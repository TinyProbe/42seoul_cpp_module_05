/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:50:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 06:43:20 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#define MIN 150
#define MAX 1

class Bureaucrat;
class AForm {
	const std::string name;
	const int signRequiredGrade;
	const int execRequiredGrade;
	bool isSigned;

	static void gradeFilter(int grade);

protected:
	static const std::string GradeTooHighException;
	static const std::string GradeTooLowException;

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
	virtual void execute(const Bureaucrat& executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
