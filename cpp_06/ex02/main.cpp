/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:33:46 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/07 23:33:47 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);

    delete ptr;
    return (0);
}