/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:45 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:46 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria{
protected:

public:
    AMateria(std::string const &type);

    std::string const &getType() const;

    virtual AMateria    *clone() const = 0;
    virtual void        use(ICharacter &target);
};

#endif