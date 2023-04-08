#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP



# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <cstdlib>
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
        void putout(std::string key, std::string value);
        void run();
};

#endif