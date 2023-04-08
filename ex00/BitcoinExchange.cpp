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
        trim(key);
        std::string value = line.substr(line.find(',') + 1);
        trim(value);
        this->dict[key] = value;
    }
    line.clear();
    this->filename = filename;
}


void BitcoinExchange::trim(std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return;
    }
    size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last - first + 1));
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

    if (inval == "NaN")
    {
        std::cout << "Error: " << "bad input => " << inkey << std::endl;
        return;
    }
    if (this->dict.count(inkey) == 0)
    {

        std::cout << "Error: " << "bad inpu2t => " << inkey << std::endl;
        return;
    }
    oval = atof(this->dict[inkey].c_str());
    val = atof(inval.c_str());
    if (val < 0)
    {
        std::cout << "Error: " << "not a positive number."<< std::endl;
        return;
    }
    if (val > 1000)
    {
        std::cout << "Error: " << "too large a number." << std::endl;
        return;
    }
    oval = val * oval;
    std::cout << inkey << " => " << inval << " = " << oval << std::endl;

}

void BitcoinExchange::run()
{

    std::string line;
    std::string key;
    std::string value;


    std::fstream *in = new std::fstream(this->filename.c_str(), std::ios::in);

    if (!in->is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        std::exit(1);
    }
    while (std::getline(*in, line))
    {
        key = line.substr(0, line.find(','));
        trim(key);
        value = line.substr(line.find(',') + 1);
        trim(value);
        putout(key, value);
    }
}
