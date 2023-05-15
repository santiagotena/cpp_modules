/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:52:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 04:33:41 by stena-he         ###   ########.fr       */
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
		void	displayHeader(void);
		bool	isContactListEmpty(void);
		void	displayContactList(void);
		void	adjustField(std::string field);
		void	displayContactInList(int index);
		int		displaySingleContact(std::string index);
		
	private:
		int		_index;
		int		_highestIndex;
		Contact	_contacts[8];
};

#endif