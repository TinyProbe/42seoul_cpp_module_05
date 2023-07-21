/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:00:23 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 18:43:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	static int _rand(int mn, int mx);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	virtual RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	virtual void execute(const Bureaucrat &executor) const;

};

#endif

