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

# define ERR_ARGC                   "Error: Provide more than one element to sort."
# define ERR_ONLY_POSITIVE          "Error: Only positive integers are allowed."
# define ERR_NO_DUPLICATES          "Error: No duplicates are allowed."
# define ERR_NO_CONTAINER_MATCH     "Error: Container not available."

class PmergeMe {
private:
    int             *_arrayNumbers;
    int             _arraySize;
    std::set<int>   _setNumbers;
    std::list<int>  _listNumbers;
    std::deque<int> _dequeNumbers;

    PmergeMe(PmergeMe &src);
    PmergeMe    &operator=(PmergeMe &src);

    template <typename Container, typename Iterator>
    void        _mergeInsertSort(Container& cont, Iterator low, Iterator high);
    template <typename Container, typename Iterator>
    void        _merge(Container& cont, Iterator low, Iterator mid, Iterator high);

    void        _exitProgram();
    int         _assignNumber(std::string element);
    bool        _isNumberPositive(int number);
    bool        _areDuplicatesPresent();
    void        _displayStartingArray();
    double      _timeToSort(std::string container);
    void        _displaySortedArray(std::string container);
    void        _displayCompletionTime(std::string container, double sortTime);

public:
    PmergeMe();
    ~PmergeMe();

    void        initialize(int argc, char *argv[]);
    void        set();
    void        list();
    void        deque();
};

#endif