/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:07:36 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/25 10:07:37 by stena-he         ###   ########.fr       */
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
    virtual void    makeSound(void) const;
    std::string     getType(void) const;
};

#endif