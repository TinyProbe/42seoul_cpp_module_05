/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:51 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 19:32:32 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat crat("goodguy", 64);
	Intern itn;
	AForm* scf = itn.makeForm("shrubbery creation", "1st street");
	AForm* rrf = itn.makeForm("robotomy request", "tom");
	AForm* ppf = itn.makeForm("presidential parden", "sam");
	AForm* unknown = itn.makeForm("sdfsdfsdfsd sdf sdfsd", "david");

	if (scf) {
		crat.signForm(*scf);
		crat.execForm(*scf);
		delete scf;
	}
	if (rrf) {
		crat.signForm(*rrf);
		crat.execForm(*rrf);
		delete rrf;
	}
	if (ppf) {
		crat.signForm(*ppf);
		crat.execForm(*ppf);
		delete ppf;
	}
	if (unknown) {
		crat.signForm(*unknown);
		crat.execForm(*unknown);
		delete unknown;
	}
}
