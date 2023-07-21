/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:51 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:04:18 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat crat("goodguy", 1);
	ShrubberyCreationForm scf0("home");
	RobotomyRequestForm rrf0("david");
	PresidentialPardonForm ppf0("superman");
	crat.signForm(scf0);
	crat.executeForm(scf0);
	crat.signForm(rrf0);
	crat.executeForm(rrf0);
	crat.signForm(ppf0);
	crat.executeForm(ppf0);
}
