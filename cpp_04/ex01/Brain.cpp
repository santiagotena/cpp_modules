/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:13:12 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/25 10:13:15 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "A brain has formed inside." << std::endl;
    return;
}

Brain::Brain(Brain const &other)
{
    *this = other;
    std::cout << "A brain has been cloned." << std::endl;
    return;
}

Brain   &Brain::operator=(Brain const &other)
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    std::cout << "The brain has rewired to be like another." << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "The brain has dissolved." << std::endl;
    return;
}

bool    Brain::operator==(const Brain &other) const
{
    for (int i = 0; i < 100; i++)
        if (_ideas[i] != other._ideas[i])
            return (false);
    return (true);
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "That idea cannot be stored there." << std::endl;
        return ;
    }
    else
        _ideas[index] = idea;
    return;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        std::cout << "No thoughts there." << std::endl;
        return (NULL);
    }
    else
        return (_ideas[index]);
}
