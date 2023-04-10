#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
    int i = 0;
    std::cout << "before: ";
    while (av[i])
    {
        _list.push_back(std::stoi(av[i]));
        std::cout << av[i] << " ";
        i++;
    }
    std::cout << std::endl;
    _vector.assign(_list.begin(), _list.end());
}

PmergeMe::~PmergeMe()
{

}


void PmergeMe::printList()
{
    std::list<int>::iterator it = _list.begin();
    while (it != _list.end())
    {
        std::cout << *it << ", ";
        it++;
    }
    std::cout << std::endl;
}

void PmergeMe::list_merge(std::list <int> &half)
{
   if (half.size() > 1)
   {
        std::list<int> half1;
        std::list<int> half2;
        split_list(half, half1, half2);
    
        list_merge(half1);
        list_merge(half2);
        half.clear();
        while (!half1.empty() && !half2.empty())
        {
            if (half1.front() < half2.front())
            {
                half.push_back(half1.front());
                half1.pop_front();
            }
            else
            {
                half.push_back(half2.front());
                half2.pop_front();
            }
        }
        while (!half1.empty())
        {
            half.push_back(half1.front());
            half1.pop_front();
        }
        while (!half2.empty())
        {
            half.push_back(half2.front());
            half2.pop_front();
        }
   }
}


void PmergeMe::vector_merge(std::vector <int> &half)
{
   if (half.size() > 1)
   {
        std::vector<int> half1;
        std::vector<int> half2;
        split_vector(half, half1, half2);
        vector_merge(half1);
        vector_merge(half2);
        half.clear();
        while (!half1.empty() && !half2.empty())
        {
            if (half1.front() < half2.front())
            {
                half.push_back(half1.front());
                half1.erase(half1.begin());
            }
            else
            {
                half.push_back(half2.front());
                half2.erase(half2.begin());
            }
        }
        while (!half1.empty())
        {
            half.push_back(half1.front());
            half1.erase(half1.begin());
        }
        while (!half2.empty())
        {
            half.push_back(half2.front());
            half2.erase(half2.begin());
        }
   }
}


std::list<int> &PmergeMe::getList()
{
    return _list;
}

void PmergeMe::split_list(std::list<int> mainlist, std::list<int> &half1, std::list<int> &half2)
{
    std::list<int>::iterator it = mainlist.begin();
    long unsigned int i = 0;
    while (it != mainlist.end())
    {
        if (i < mainlist.size() / 2)
            half1.push_back(*it);
        else
            half2.push_back(*it);
        it++;
        i++;
    }
}


void PmergeMe::split_vector(std::vector<int> mainlist, std::vector<int> &half1, std::vector<int> &half2)
{
    std::vector<int>::iterator it = mainlist.begin();
    long unsigned int i = 0;
    while (it != mainlist.end())
    {
        if (i < mainlist.size() / 2)
            half1.push_back(*it);
        else
            half2.push_back(*it);
        it++;
        i++;
    }
}

std::vector<int> &PmergeMe::getVector()
{
    return _vector;
}

void PmergeMe::print()
{
    std::cout << "after: ";
    std::list<int>::iterator it = _list.begin();
    while (it != _list.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std :: cout << "to process a range of " << _list.size() << " elements with std::list : " << _list_time << " us" << std::endl;
    std :: cout << "to process a range of " << _vector.size() << " elements with std::vector : " << _vector_time << " us" << std::endl;
}

void PmergeMe::timeset()
{
    static int i = 0;
    if (!(i % 2))
    {
        _start = std::chrono::high_resolution_clock::now();
    }
    else
    {
        std::chrono::high_resolution_clock::time_point _end = std::chrono::high_resolution_clock::now();
        this->duration = _end - _start;
    }   
    i++;
}

void PmergeMe::set_list_time()
{
    this->_list_time = this->duration.count() * 1000000;
}

void PmergeMe::set_vector_time()
{
    this->_vector_time = this->duration.count() * 1000000;
}