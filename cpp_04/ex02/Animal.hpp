/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:12:54 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 00:12:55 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string     _type;

public:
    Animal(void);
    Animal(Animal const &other);
    Animal  &operator=(Animal const &other);
    virtual ~Animal(void);

    bool            operator==(Animal const &other) const;
    virtual void    makeSound(void) const = 0;
    std::string     getType(void) const;
};

#endif