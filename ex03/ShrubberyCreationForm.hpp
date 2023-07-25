/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:59:38 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 06:12:48 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
	virtual ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void execute(const Bureaucrat &executor) const;

};

#endif
