/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:52:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 11:03:06 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iomanip>
# include "Contact.hpp"

# define BOOK_SIZE 8

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);

		int		addContact(void);
		bool	isContactListEmpty(void);
		void	displayContactList(void);
		int		displaySingleContact(std::string index);
		
	private:
		int		_index;
		int		_highestIndex;
		Contact	_contacts[8];
		
		void	_displayHeader(void) const;
		void	_adjustField(std::string field) const;
		void	_displayContactInList(int index);
};

#endif