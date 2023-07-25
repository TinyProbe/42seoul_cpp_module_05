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
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	Intern intern;
	AForm *scf = intern.makeForm("shrubbery creation", "scf1");
	AForm *rrf = intern.makeForm("robotomy request", "rrf1");
	AForm *ppf = intern.makeForm("presidential parden", "ppf1");
	if (scf != NULL) { delete scf; }
	if (rrf != NULL) { delete rrf; }
	if (ppf != NULL) { delete ppf; }
}

