/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:50:32 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/14 23:18:01 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{

public:
	Contact(void);
	~Contact(void);

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumberStr;
	int			phoneNumberInt;
	std::string	darkestSecret;
		

};

#endif