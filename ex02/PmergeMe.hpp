#ifndef PMERGEME_HPP
# define PMERGEME_HPP 



# include <iostream>
# include <list>
# include <vector>
# include <chrono>

class PmergeMe
{
    private:
        std::list<int> _list;
        std::vector<int> _vector;
        double _list_time;
        double _vector_time;
        std::chrono::high_resolution_clock::time_point _start;
        std::chrono::duration<double> duration;

    public:
        PmergeMe(char **av);
        ~PmergeMe();
        void printList();
        void split_list(std::list<int> mainlist, std::list<int> &half1, std::list<int> &half2);
        void list_merge(std::list <int> &half);
        void vector_merge(std::vector <int> &half);
        void split_vector(std::vector<int> mainvector, std::vector<int> &half1, std::vector<int> &half2);
        void print();
        void timeset();
        void set_list_time();
        void set_vector_time();
        std::list<int> &getList();
        std::vector<int> &getVector();
};

#endif