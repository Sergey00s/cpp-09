#include "RPN.hpp"



int main(int argc, char const *argv[])
{


    if (argc != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    RPN test(argv[1]);
    test.run();
    return 0;
}
