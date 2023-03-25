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
        std::fstream *in;
        std::map<std::string, std::string> dict;
        std::map<std::string, std::string> indict;

    public:
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        void putout(std::string key, std::string value);
        void run();
};

#endif