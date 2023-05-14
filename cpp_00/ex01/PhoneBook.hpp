/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:52:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/14 23:25:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

# define ERR_BLANK "Error: No empty fields allowed"

class Phonebook {

public:
	Phonebook(void);
	~Phonebook(void);

	int	addContact(void);
	
private:
	int		_index;
	Contact	_contacts[8];

	
};

#endif