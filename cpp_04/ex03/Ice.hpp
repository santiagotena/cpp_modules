/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:52 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
private:
    std::string     _type;

public:
    Ice();
    Ice(Ice const &other);
    Ice     &operator=(Ice const &other);
    virtual ~Ice();

    virtual AMateria    *clone() const;
    virtual void        use(ICharacter &target);
};

#endif