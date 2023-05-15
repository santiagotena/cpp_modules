/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:31 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 02:53:32 by stena-he         ###   ########.fr       */
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
	
	if (this->_index > (BOOK_SIZE - 1))
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
	std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
	return ;
}

void	adjustField(std::string field) {
	return ;
}

void	Phonebook::displayContactInList(int index) {
	// this->_contacts[index];
	return ;
}

void	Phonebook::displayContactList(void) {
	displayHeader();
	for (int i = 0; i < this->_index; i++)
	{
		displayContactInList(i);
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	return ;
}

void	Phonebook::displaySingleContact(std::string index) {
	// Check if index is number
	// Check if within bounds
	// Check if field not empty
	// Print contact
	return ;
}
