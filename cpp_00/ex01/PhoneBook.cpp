/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:31 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 11:24:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook(void) : _index(0), _highestIndex(0) {
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

int	Phonebook::addContact(void) {	
	Contact *currentContact;
	
	if (this->_index > (BOOK_SIZE - 1))
		this->_index = 0;
	currentContact = &this->_contacts[this->_index];
	currentContact->setContactIndex(this->_index);
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
	if (this->_highestIndex < this->_index)
		this->_highestIndex = this->_index;
	
	return (0);
}

void	Phonebook::_displayHeader(void) const {
	std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|   Index  |First Name|Last Name | Nickname |" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
	return ;
}

void	Phonebook::_adjustField(std::string field) const{
	std::cout << "|";
	if (field.length() >= 10)
		std::cout << field.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << field;
	return ;
}

void	Phonebook::_displayContactInList(int index) {
	_adjustField(this->_contacts[index].getContactIndex());
	_adjustField(this->_contacts[index].getFirstName());
	_adjustField(this->_contacts[index].getLastName());
	_adjustField(this->_contacts[index].getNickname());
	std::cout << "|" << std::endl;
	return ;
}

bool	Phonebook::isContactListEmpty(void) {
	return (this->_contacts[0].getFirstName().empty());
}

void	Phonebook::displayContactList(void) {
	_displayHeader();
	for (int i = 0; i < this->_highestIndex; i++)
	{
		_displayContactInList(i);
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	return ;
}

int	Phonebook::displaySingleContact(std::string index) {
	int	indexInt;
	
	try {
		indexInt = std::stoi(index);
	}
	catch (std::invalid_argument) {
		std::cout << ERR_NOT_A_NUMBER << std::endl;
		return (-1);
	}
	if (indexInt < 0 || indexInt > (BOOK_SIZE - 1)) {
		std::cout << ERR_INVALID_INDEX << std::endl;
		return (-1);
	}
	if (this->_contacts[indexInt].getFirstName().empty())
	{
		std::cout << ERR_EMPTY_CONTACT << std::endl;
		return (-1);
	}
	std::cout << this->_contacts[indexInt].getFirstName() << std::endl;
	std::cout << this->_contacts[indexInt].getLastName() << std::endl;
	std::cout << this->_contacts[indexInt].getNickname() << std::endl;
	std::cout << this->_contacts[indexInt].getPhoneNumber() << std::endl;
	std::cout << this->_contacts[indexInt].getDarkestSecret() << std::endl;
	return (0);
}
