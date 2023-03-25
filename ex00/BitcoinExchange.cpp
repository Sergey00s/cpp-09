#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string filename)
{
    this->ff = new std::fstream("data.csv");
    if (!this->ff->is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        std::exit(1);
    }
    std::string line;
    while (std::getline(*this->ff, line))
    {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        this->dict[key] = value;
    }

    this->in = new std::fstream(filename.c_str());
    if (!this->in->is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        std::exit(1);
    }
    while (std::getline(*this->in, line))
    {
        std::string key = line.substr(0, line.find('|'));
        std::string value = line.substr(line.find('|') + 1);
        this->indict[key] = value;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    this->ff->close();
    delete this->ff;
}

void BitcoinExchange::putout(std::string inkey, std::string inval)
{
    int val;
    float oval;

    oval = atof(this->dict[inkey].c_str());
    val = atof(inval.c_str());
    oval = val * oval; 
    std::cout << inkey << " => " << inval << " = " << oval << std::endl;

}

void BitcoinExchange::run()
{
    std::map<std::string, std::string>::iterator it;
    for (it = this->indict.begin(); it != this->indict.end(); it++)
    {
       putout(it->first, it->second);
    }
}
