/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:56:51 by tkong             #+#    #+#             */
/*   Updated: 2023/02/16 21:20:29 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat b("goodGuy", 10);
	std::cout << b << '\n';
	try {
		b.upGrade(10);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	};
	std::cout << b << '\n';
	try {
		b.upGrade(9);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	};
	std::cout << b << '\n';
	try {
		b.downGrade(300);
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	};
	std::cout << b << '\n';
}

