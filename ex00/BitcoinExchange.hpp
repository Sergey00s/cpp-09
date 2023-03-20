#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP



# include <iostream>
# include <string>
# include <vector>
# include <map>

class BitcoinExchange
{
    private:
        std::fstream ff("bitcoin.csv");
        std::map<std::string, std::string> dict;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void run();
};

#endif