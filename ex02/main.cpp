#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cout << "Usage: ./PmergeMe ..." << std::endl;
        return 1;
    }
    PmergeMe *list = new PmergeMe(av + 1);
    //list->timeset();
    //list->list_merge(list->getList());
    //list->timeset();
    //list->set_list_time();
    list->timeset();
    list->vector_merge(list->getVector());
    list->timeset();

    list->print();
    delete list;
    return 0;
}