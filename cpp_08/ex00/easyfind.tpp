/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:55:57 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/12 17:55:58 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
bool easyfind(T &container, int value) {
    typename T::iterator iter;
    iter = std::find(container.begin(), container.end(), value);
    if (iter != container.end())
        return (true);
    else
        return (false);
}
