/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:51 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:48:22 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat crat("goodguy", 1);
	Intern itn;
	AForm* scf = itn.makeForm("shrubbery creation", "1st street");
	AForm* rrf = itn.makeForm("robotomy request", "tom");
	AForm* ppf = itn.makeForm("presidential parden", "sam");
	AForm* unknown = itn.makeForm("sdfsdfsdfsd sdf sdfsd", "david");

	if (scf) {
		crat.signForm(*scf);
		crat.executeForm(*scf);
		delete scf;
	}
	if (rrf) {
		crat.signForm(*rrf);
		crat.executeForm(*rrf);
		delete rrf;
	}
	if (ppf) {
		crat.signForm(*ppf);
		crat.executeForm(*ppf);
		delete ppf;
	}
	if (unknown) {
		crat.signForm(*unknown);
		crat.executeForm(*unknown);
		delete unknown;
	}
}
