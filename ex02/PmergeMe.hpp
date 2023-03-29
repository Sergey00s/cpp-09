#ifndef PMERGEME_HPP
# define PMERGEME_HPP 



# include <iostream>
# include <list>


class PmergeMe
{
    private:
        std::list<int> _list;

    public:
        PmergeMe(char **av);
        ~PmergeMe();
        void printList();
        void merge(PmergeMe &other);
        
};

#endif