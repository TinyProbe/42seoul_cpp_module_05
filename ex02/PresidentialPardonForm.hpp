/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:01:28 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 18:43:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();
	virtual PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	virtual void execute(const Bureaucrat &executor) const;

};

#endif

