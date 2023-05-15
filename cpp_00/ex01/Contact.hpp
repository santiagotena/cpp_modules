/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:50:32 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 03:34:20 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

# define ERR_EMPTY_FIELD "Error: No empty fields allowed"
# define ERR_NOT_A_NUMBER "Error: Input is not a number"
# define ERR_INVALID_INDEX "Error: Index is out of bounds"
# define ERR_EMPTY_CONTACT "Error: No contact in that index"

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		int			setContactIndex(int index);
		int			setFirstName(void);
		int			setLastName(void);
		int			setNickname(void);
		int			setPhoneNumber(void);
		int			setDarkestSecret(void);
		
		std::string	getContactIndex(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);

	private:
		int			_contactIndex;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif