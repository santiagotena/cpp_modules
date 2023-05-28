/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:41:11 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 16:41:12 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
    std::string     _type;

public:
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const &other);
    WrongAnimal  &operator=(WrongAnimal const &other);
    virtual ~WrongAnimal(void);

    bool            operator==(WrongAnimal const &other) const;
    void            makeSound(void) const;
    std::string     getType(void) const;
};

#endif
