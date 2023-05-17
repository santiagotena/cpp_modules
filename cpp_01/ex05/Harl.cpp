/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:43:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 20:41:12 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << "Harl has entered the room." << std::endl;
	return ;
}

Harl::~Harl(void) {
	std::cout << "Harl has left the room." << std::endl;
	return ;
}

void	Harl::complain(std::string level) {
	std::string	commentLevels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*functions[4])(void) =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	for (int i = 0; i < 4 ; i++) {
		if (commentLevels[i] == level) {
			(this->*functions[i])();
			return;
		}		
	}
	std::cout << "This is unexpected behavior from Harl." << std::endl;
	return ;
}

void	Harl::_debug(void)
{
    std::cout << "[DEBUG]\nI love to get extra bacon for my 7XL-double-cheese-triple-pic"
        "kle-special-ketchup burger. I just love it!" << std::endl;
}

void	Harl::_info(void)
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon cost more money. You don'"
        "t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::_warning(void)
{
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve bee"
        "n coming here for years and you just started working here last month."
        << std::endl;
}

void	Harl::_error(void)
{
    std::cout << "[ERROR]\nThis is unacceptable, I want to speak to the manager now."
        << std::endl;
}
