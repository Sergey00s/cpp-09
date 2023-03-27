#include "RPN.hpp"


RPN::RPN(std::string line)
{
    std::string::iterator it = line.begin();
    std::stack<char> stacktemp;
    std::stack<char> stacktemp2;
    while (it != line.end())
    {
        if (*it == ' ')
        {
            it++;
            continue;
        }
        if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            stacktemp2.push(*it);
            it++;
            continue;
        }
        if (*it >= '0' && *it <= '9')
        {
            int number = 0;
            while (*it >= '0' && *it <= '9')
            {
                number = number * 10 + (*it - '0');
                it++;
            }
            stacktemp.push(number);
            continue;
        }
        else
            {
                std::cout << "Error" << std::endl;
                std::exit(1);
                return;
            }
        it++;
    }
    while (!stacktemp.empty())
    {
        stack.push(stacktemp.top());
        stacktemp.pop();
    }

    while (!stacktemp2.empty())
    {
        operators.push(stacktemp2.top());
        stacktemp2.pop();
    }

}



RPN::~RPN()
{

}


void RPN::run()
{
    while (!operators.empty())
    {
        if (stack.size() < 2)
        {
            std::cout << "Error" << std::endl;
            return;
        }
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        char op = operators.top();
        if (!(op == '+' || op == '-' || op == '*' || op == '/'))
            return;
        operators.pop();
        if (op == '+')
            stack.push(a + b);
        if (op == '-')
            stack.push(a - b);
        if (op == '*')
            stack.push(a * b);
        if (op == '/')
            stack.push(a / b);
    }
    std::cout << stack.top() << std::endl;
}


