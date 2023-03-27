#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <stack>


class RPN
{
    private:
        std::stack<char> operators;
        std::stack<int> stack;
    public:
        RPN(std::string line);
        ~RPN();
        void run();
};


#endif