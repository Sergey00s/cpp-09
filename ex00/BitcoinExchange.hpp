#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP



# include <iostream>
# include <fstream>
# include <vector>
# include <map>

class BitcoinExchange
{
    private:
        std::fstream *ff;
        std::map<std::string, std::string> dict;
        std::string filename;

    public:
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        void trim(std::string &str);
        std::string mostsimilar(std::string year, std::string month, std::string day);
        void putout(std::string key, std::string value);
        void run();
};

#endif