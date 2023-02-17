/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:00:23 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 06:12:48 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	virtual void execute(const Bureaucrat& executor) const;

};

#endif
