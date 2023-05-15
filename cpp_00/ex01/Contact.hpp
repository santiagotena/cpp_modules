/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:50:32 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 11:27:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

# define ERR_INVALID_CMD "Error: Invalid command"
# define ERR_EMPTY_FIELD "Error: No empty fields allowed"
# define ERR_NOT_A_NUMBER "Error: Input is not a number"
# define ERR_INVALID_INDEX "Error: Index is out of bounds"
# define ERR_EMPTY_CONTACT "Error: No contact in that index"
# define ERR_NB_OUT_BOUNDS "Error: Number is out of bounds"

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
		
		std::string	getContactIndex(void) const ;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;

	private:
		int			_contactIndex;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif