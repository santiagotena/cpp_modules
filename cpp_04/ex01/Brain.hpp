/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:13:09 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/25 10:13:10 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MODULES_BRAIN_HPP
# define CPP_MODULES_BRAIN_HPP

# include <iostream>

class Brain
{
protected:
    std::string   _ideas[100];

public:
    Brain();
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);
    ~Brain();

    bool        operator==(Brain const &other) const;
    void        setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};

#endif