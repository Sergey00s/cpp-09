#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
    this->ff = new std::fstream("data.csv", std::ios::in);
    if (!this->ff->is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(*this->ff, line))
    {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        this->dict[key] = value;
    }
}


BitcoinExchange::~BitcoinExchange()
{
    this->ff->close();
    delete this->ff;
}

void BitcoinExchange::run()
{
    while (true)
    {
        this->dict
    }
    
}
