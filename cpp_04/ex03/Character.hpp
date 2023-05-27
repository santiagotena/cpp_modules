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

# define INVENTORY_SIZE 4
# define STORAGE_SIZE 100

class Character : public ICharacter
{
private:
    std::string     _name;
    AMateria        *_inventory[INVENTORY_SIZE];
    AMateria        *_storage[STORAGE_SIZE];

    void            _nullInventoryAndStorage();

public:
    Character();
    Character(std::string name);
    Character(Character const &other);
    Character   &operator=(Character const &other);
    ~Character();

    virtual std::string const   &getName() const;
    virtual void                equip(AMateria *m);
    virtual void                unequip(int idx);
    virtual void                use(int idx, ICharacter &target);
    void                        displayInventory() const;
    void                        displayStorage() const;
};

#endif