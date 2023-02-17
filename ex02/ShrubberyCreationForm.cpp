/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:59:40 by tkong             #+#    #+#             */
/*   Updated: 2023/02/17 09:11:12 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) :
	AForm(rhs) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm(target, 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this == &rhs) {
		return *this;
	}
	*dynamic_cast<AForm*>(this) = *dynamic_cast<const AForm*>(&rhs);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() <= this->getExecReqGrad()) {
		std::ofstream ofs(this->getName() + "_shrubbery");
		if (!ofs.is_open()) {
			throw std::string("ShrubberyCreationForm : File open failed");
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
	} else {
		throw std::runtime_error(AForm::GradeTooLowException);
	}
}
