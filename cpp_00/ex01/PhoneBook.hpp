/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:52:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/15 00:58:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);

		int		addContact(void);
		void	displayHeader(void);
		void	displayContactList(void);
		void	displayFooter(void);
		void	displayContact(int index);
		
	private:
		int		_index;
		Contact	_contacts[8];
};

#endif