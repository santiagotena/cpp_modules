/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:36:30 by stena-he          #+#    #+#             */
/*   Updated: 2023/06/17 10:36:39 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <set>
# include <list>
# include <deque>

class PmergeMe {
private:
    std::string     _container;
    std::set<int>   _setNumbers;
    std::list<int>  _listNumbers;
    std::deque<int> _dequeNumbers;

    PmergeMe();
    PmergeMe(PmergeMe &src);
//    PmergeMe    &operator=(PmergeMe &src);

public:
    PmergeMe(std::string);
    ~PmergeMe();



};

#endif