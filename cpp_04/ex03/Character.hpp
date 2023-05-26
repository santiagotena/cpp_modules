/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:47 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character {
private:
    std::string     _name;
    AMateria        *_inventory[4];
    AMateria        *_storage[100];

public:
    Character();
    Character(std::string name);
    //Copy constructors, both, need to create deep copies
    //Materias need to be deleted before the new ones are added to their inventory
    ~Character(); // Delete Materias

};


#endif