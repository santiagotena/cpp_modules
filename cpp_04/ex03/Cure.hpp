/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:50 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:51 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
private:
    std::string     _type;

public:
    Cure();
    Cure(Cure const &other);
    Cure    &operator=(Cure const &other);
    virtual ~Cure();

    virtual AMateria    *clone() const;
    virtual void        use(ICharacter &target);
};

#endif