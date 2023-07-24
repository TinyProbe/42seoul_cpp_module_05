/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:59:40 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:37:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) :
	AForm(rhs) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm(target, 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	dynamic_cast<AForm &>(*this) = dynamic_cast<const AForm &>(rhs);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	int err = 0;
	err = (!getSign() ? 1 : err);
	err = (executor.getGrade() > getExecReqGrad() ? 2 : err);
	switch (err) {
		case 1: throw std::runtime_error("can't execute about doesn't signed form");
			break;
		case 2: throw AForm::GradeTooLowException();
			break;
		default: break;
	}
	std::ofstream ofs(getName() + "_shrubbery");
	if (!ofs.is_open()) {
		throw std::runtime_error("Failed to open");
	}
	ofs << "                                                     .           \n"
		<< "                                          .         ;            \n" 
		<< "             .              .              ;%     ;;             \n" 
		<< "               ,           ,                :;%  %;              \n"
		<< "                :         ;                   :;%;'      .,      \n"
		<< "       ,.        %;     %;            ;        %;'     ,;        \n"
		<< "         ;       ;%;  %%;        ,     %;    ;%;    ,%;'         \n"
		<< "          %;       %;%;      ,  ;       %;  ;%;   ,%;'           \n" 
		<< "           ;%;      %;        ;%;        % ;%;  ,%;'             \n"
		<< "            `%;.     ;%;     %;'         `;%%;.%;'               \n"
		<< "             `:;%.    ;%%. %@;        %; ;@%;%'                  \n"
		<< "                `:%;.  :;bd%;          %;@%;'                    \n"
		<< "                  `@%:.  :;%.         ;@@%;'                     \n"
		<< "                    `@%.  `;@%.      ;@@%;                       \n"
		<< "                      `@%%. `@%%    ;@@%;                        \n"
		<< "                        ;@%. :@%%  %@@%;                         \n"
		<< "                          %@bd%%%bd%%:;                          \n"
		<< "                            #@%%%%%:;;                           \n"
		<< "                            %@@%%%::;                            \n"
		<< "                            %@@@%(o);  . '                       \n"
		<< "                            %@@@o%;:(.,'                         \n"
		<< "                        `.. %@@@o%::;                            \n"
		<< "                           `)@@@o%::;                            \n"
		<< "                            %@@(o)::;                            \n"
		<< "                           .%@@@@%::;                            \n"
		<< "                           ;%@@@@%::;.                           \n"
		<< "                          ;%@@@@%%:;;;.                          \n"
		<< "                      ...;%@@@@@%%:;;;;,..                       \n";
	ofs.close();
}
