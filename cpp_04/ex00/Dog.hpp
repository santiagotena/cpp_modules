/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:40 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string     _type;

    public:
        Dog(void);
        Dog(Dog const &other);
        Dog &operator=(Dog const &other);
        ~Dog(void);

        bool    operator==(Dog const &other) const;
        void    makeSound(void);
};

#endif