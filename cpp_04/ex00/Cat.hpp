/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:43 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat(void);
    Cat(Cat const &other);
    Cat &operator=(Cat const &other);
    ~Cat(void);

    bool    operator==(Cat const &other) const;
    void    makeSound(void) const;
};

#endif