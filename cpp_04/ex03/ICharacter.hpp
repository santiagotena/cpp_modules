/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:53 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:54 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter {
public:
    virtual                     ~ICharacter() {}
    virtual std::string const   &getName() const = 0;
    virtual void                equip(AMateria *m) = 0;
    virtual void                unequip(int idx) = 0;
    virtual void                use(int idx, ICharacter &target) = 0;
};

#endif