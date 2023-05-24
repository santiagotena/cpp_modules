/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:38 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:39 by stena-he         ###   ########.fr       */
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
    ~Animal(void);

    bool            operator==(Animal const &other) const;
    void virtual    makeSound(void) const;
    std::string     getType(void) const;
};

#endif