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
        if (key == "date")
            continue;
        trim(key);
        std::string value = line.substr(line.find(',') + 1);
        trim(value);
        this->dict[key] = value;
    }
    line.clear();
    this->filename = filename;


    // std::map<std::string, std::string>::iterator it = this->dict.begin();
    // auto f = fopen("dene", "w");
    // while (it != this->dict.end())
    // {
    //     fprintf(f, "|%s=>%s|\n", it->first.c_str(), it->second.c_str());
    //     it++;
    // }
    // fclose(f);
    // getchar();
}


void BitcoinExchange::trim(std::string &str)
{
    size_t first = str.find_first_not_of("  \t");
    if (std::string::npos == first)
    {
        return;
    }
    size_t last = str.find_last_not_of("  \t");
    str = str.substr(first, (last - first + 1));
}

BitcoinExchange::~BitcoinExchange()
{
    this->ff->close();
    delete this->ff;
}

std::string BitcoinExchange::mostsimilar(std::string year, std::string month, std::string day)
{
    while (this->dict.count(year + "-" + month + "-" + day) == 0)
    {
        if (std::stoi(day) > 1)
        {
            day = std::to_string(std::stoi(day) - 1);
        }
        else if (std::stoi(month) > 1)
        {
            month = std::to_string(std::stoi(month) - 1);
            day = "31";
        }
        else
        {
            year = std::to_string(std::stoi(year) - 1);
            month = "12";
            day = "31";
        }
    }
    return year + "-" + month + "-" + day;
}

void BitcoinExchange::putout(std::string inkey, std::string inval)
{
    float val;
    float oval;
    std::string key;
    key = inkey;
    if (inval == "NaN")
    {
        std::cout << "Error: " << "bad inpwut => " << inkey << std::endl;
        return;
    }
    if (this->dict.count(inkey) == 0)
    {
        std::string year = inkey.substr(0, 4);
        std::string month = inkey.substr(5, 2);
        std::string day = inkey.substr(8, 2);


        if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        {
            std::cout << "Error: " << "bad input => " << day << std::endl;
            return;
        }
        if (std::stoi(month) > 12 || std::stoi(month) < 1)
        {
            std::cout << "Error: " << "bad input => " << inkey << std::endl;
            return;
        }
        if (std::stoi(day) > 31 || std::stoi(day) < 1)
        {
            std::cout << "Error: " << "bad input => " << day << std::endl;
            return;
        }
        std::string key = mostsimilar(year, month, day);
        inkey = key;
    }

    val = std::stof(inval);
    oval = std::stof(this->dict[inkey]);

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

    oval = oval * (float)val;
    std::cout << key << " => " << inval << " = " << oval << std::endl;

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
        key = line.substr(0, line.find('|'));
        trim(key);
        if (key == "date")
            continue;
        value = line.substr(line.find('|') + 1);
        trim(value);
        putout(key, value);
    }
    in->close();
    delete in;
}
