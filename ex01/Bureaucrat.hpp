/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:51 by tkong             #+#    #+#             */
/*   Updated: 2023/02/16 21:47:01 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define MIN 150
#define MAX 1

class Bureaucrat {
	static const std::string GradeTooHighException;
	static const std::string GradeTooLowException;
	const std::string name;
	int grade;

	static void gradeFilter(int grade);

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& rhs);
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, int grade);
	virtual ~Bureaucrat();
	virtual Bureaucrat& operator=(const Bureaucrat& rhs);

	virtual const std::string& getName() const;
	virtual const int& getGrade() const;
	virtual void upGrade(int grade);
	virtual void downGrade(int grade);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
