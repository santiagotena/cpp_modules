/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:31 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 01:59:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook(void) {
	this->_index = 0;
	std::cout << "Phonebook created" << std::endl;
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "Phonebook destroyed" << std::endl;
	return ;
}

int	Phonebook::addContact(void) {	
	Contact *currentContact;
	
	if (this->_index > 7)
		this->_index = 0;
	currentContact = &this->_contacts[this->_index];
	if (currentContact->setFirstName() != 0)
		return (-1);
	if (currentContact->setLastName() != 0)
		return (-1);
	if (currentContact->setNickname() != 0)
		return (-1);
	if (currentContact->setPhoneNumber() != 0)
		return (-1);
	if (currentContact->setDarkestSecret() != 0)
		return (-1);
	this->_index++;
	return (0);
}

void	Phonebook::displayHeader(void) {
	return ;
}

void	Phonebook::displayContactList(void) {
	return ;
}

void	Phonebook::displayFooter(void) {
	return ;
}

void	Phonebook::displayContact(int index) {
	return ;
}
