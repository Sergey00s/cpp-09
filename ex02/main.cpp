#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cout << "Usage: ./PmergeMe [list1] [list2] ..." << std::endl;
        return 1;
    }
    PmergeMe *list = new PmergeMe(av + 1);
    list->merge(*list);
    list->printList();
    delete list;
    return 0;
}