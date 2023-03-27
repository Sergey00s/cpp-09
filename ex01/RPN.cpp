#include "RPN.hpp"


RPN::RPN(std::string line)
{
    this->tokens = "+-*/0123456789";
    std::string::iterator it = line.begin();

    while (it != line.end())
    {
        if (this->tokens.find(*it) != std::string::npos)
        {
            this->stack.push(*it);
        }
    }
}


RPN::~RPN()
{

}


void RPN::run()
{
    std::stack<char> stack;
    std::string tokens = "+-*/0123456789";
    std::string::iterator it = this->tokens.begin();


    int res;
    std::size_t pos;
    while (it != this->tokens.end())
    {
        if (pos = tokens.find(*it) != std::string::npos)
        {
            for (int i = 0; i < pos; i++)
            {
                if (stack.size() < 2)
                {
                    std::cout << "Error: not enough operands" << std::endl;
                    return;
                }
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (pos == 0)
                {
                    res = a + b;
                }
                else if (pos == 1)
                {
                    res = a - b;
                }
                else if (pos == 2)
                {
                    res = a * b;
                }
                else if (pos == 3)
                {
                    res = a / b;
                }
                stack.push(res);
            }
        }
    }
}


