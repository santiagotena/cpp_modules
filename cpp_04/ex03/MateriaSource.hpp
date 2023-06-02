/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:32:01 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:32:02 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define MEMORY_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
    AMateria    *_inventory[MEMORY_SIZE];

    void        _nullInventory();

public:
    MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource   &operator=(MateriaSource const &other);
    ~MateriaSource();

    void        learnMateria(AMateria*);
    AMateria*   createMateria(std::string const & type);
    void        displayMemory() const;
};

#endif