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
    int             *_arrayNumbers;
    int             _arraySize;
    std::set<int>   _setNumbers;
    std::list<int>  _listNumbers;
    std::deque<int> _dequeNumbers;

    PmergeMe(PmergeMe &src);
    PmergeMe    &operator=(PmergeMe &src);


public:
    PmergeMe();
    ~PmergeMe();

    void    initialize(int argc, char *argv[]);
    void    set();
    void    list();
    void    deque();

    template <typename Container, typename Iterator>
    void    mergeInsertSort(Container& cont, Iterator low, Iterator high);
    template <typename Container, typename Iterator>
    void    merge(Container& cont, Iterator low, Iterator mid, Iterator high);
};

#endif