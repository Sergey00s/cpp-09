#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
    int i = 0;
    while (av[i])
    {
        _list.push_back(atoi(av[i]));
        i++;
    }
}

PmergeMe::~PmergeMe()
{
}


void PmergeMe::printList()
{
    std::list<int>::iterator it = _list.begin();
    while (it != _list.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}


void PmergeMe::merge(PmergeMe &other)
{
    std::list<int>::iterator it = _list.begin();
    std::list<int>::iterator it2 = other._list.begin();
    while (it != _list.end() && it2 != other._list.end())
    {
        if (*it > *it2)
        {
            _list.insert(it, *it2);
            it2++;
        }
        else
            it++;
    }
}

