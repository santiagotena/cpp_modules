/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:41:13 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 16:41:14 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(WrongCat const &other);
    WrongCat &operator=(WrongCat const &other);
    virtual ~WrongCat(void);

    bool    operator==(WrongCat const &other) const;
    void    makeSound(void) const;
};

#endif