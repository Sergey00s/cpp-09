#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <stack>


class RPN
{
    private:
        std::stack<char> stack;
        std::string tokens;
    public:
        RPN(std::string line);
        ~RPN();
        void run();
};


#endif