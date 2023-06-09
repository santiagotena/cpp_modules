/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:30:28 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 11:42:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int	Contact::setContactIndex(int index) {
	this->_contactIndex = index;
	return (0);
}

int	Contact::setFirstName(void) {
	std::string	input;
	
	while (1) {
		std::cout << "Enter contact's First Name:" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || std::cin.eof())
			return (-1);
		else if (input.empty())
			std::cout << ERR_EMPTY_FIELD << std::endl;
		else
			break ;
	}
	this->_firstName = input;
	return (0);
}

int	Contact::setLastName(void) {
	std::string	input;
	
	while (1) {
		std::cout << "Enter contact's Last Name:" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || std::cin.eof())
			return (-1);
		else if (input.empty())
			std::cout << ERR_EMPTY_FIELD << std::endl;
		else
			break ;
	}
	this->_lastName = input;
	return (0);
}

int	Contact::setNickname(void) {
	std::string	input;
	
	while (1) {
		std::cout << "Enter contact's Nickname:" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || std::cin.eof())
			return (-1);
		else if (input.empty())
			std::cout << ERR_EMPTY_FIELD << std::endl;
		else
			break ;
	}
	this->_nickname = input;
	return (0);
}

int	Contact::setPhoneNumber(void) {
	std::string	input;
	
	while (1) {
		std::cout << "Enter contact's Phone Number:" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || std::cin.eof())
			return (-1);
		else if (input.empty())
			std::cout << ERR_EMPTY_FIELD << std::endl;
		else {
			try {
				if (std::stoi(input) < 0)
				{
					std::cout << ERR_NB_OUT_BOUNDS << std::endl;
					continue ;
				}
			}
			catch (std::out_of_range) {
				std::cout << ERR_NB_OUT_BOUNDS << std::endl;
				continue ;
			}
			catch (std::invalid_argument) {
				std::cout << ERR_NOT_A_NUMBER << std::endl;
				continue ;
			}
			break ;
		}
	}
	this->_phoneNumber = input;
	return (0);
}

int	Contact::setDarkestSecret(void) {
	std::string	input;
	
	while (1) {
		std::cout << "Enter contact's Darkest Secret:" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || std::cin.eof())
			return (-1);
		else if (input.empty())
			std::cout << ERR_EMPTY_FIELD << std::endl;
		else
			break ;
	}
	this->_darkestSecret = input;
	return (0);
}

std::string	Contact::getContactIndex(void) const {
	return (std::to_string(this->_contactIndex));
}

std::string	Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string Contact::getLastName(void) const {
	return(this->_lastName);
}

std::string	Contact::getNickname(void) const {
	return(this->_nickname);
}

std::string Contact::getPhoneNumber(void) const {
	return(this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const {
	return(this->_darkestSecret);
}
