/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:20:18 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 09:43:14 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;
class Intern {

public:
	Intern();
	Intern(const Intern &rhs);
	virtual ~Intern();
	virtual Intern &operator=(const Intern &rhs);

	virtual AForm *makeForm(const std::string &form, const std::string &target) const;

};

#endif
