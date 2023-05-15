/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:24 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 04:25:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	command;
	std::string	index;
	
	while (1) {
		std::cout << "Enter a command: <ADD> <SEARCH> <EXIT>" << std::endl;
		std::getline(std::cin, command);
		if (command.compare("EXIT") == 0 || std::cin.eof())
			return (0);
		else if (command.compare("ADD") == 0) {
			if (phonebook.addContact() != 0)
				return (0);
		}
		else if (command.compare("SEARCH") == 0) {				
			phonebook.displayContactList();
			if(phonebook.isContactListEmpty())
				continue ;
			while (1) {
				std::cout << "Enter index of contact to expand:" << std::endl;
				std::getline(std::cin, index);
				if (index.compare("EXIT") == 0 || std::cin.eof())
					return (0);
				if (phonebook.displaySingleContact(index) == 0)
					break ;
			}
		} 
		else
			std::cout << "Error: Invalid command" << std::endl;
	}
	return (0);
}