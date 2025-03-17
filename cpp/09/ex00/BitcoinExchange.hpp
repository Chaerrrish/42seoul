#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
# include <map>

class BitcoinExchange {
    private :
        std::map<std::string, double> data;
        bool isLeapYear(int year) const;
        bool isValidDate(const std::string &date) const;
    public :
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& BitcoinExchange);
        BitcoinExchange& operator=(const BitcoinExchange& BitcoinExchange);

        class Error : public std::exception {
          public:
            const char* what() const throw();
        };
        BitcoinExchange(const std::string &dbFile);
        double getClosestRate(const std::string &date) const;
        void processInputFile(const std::string &inputFile) const;
};

#endif