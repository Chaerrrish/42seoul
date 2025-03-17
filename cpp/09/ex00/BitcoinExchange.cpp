#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->data = other.data;
    }
    return *this;
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;  // 형식이 YYYY-MM-DD가 아니면 잘못된 날짜
    }

    int year, month, day;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-') {
        return false;  // 파싱 오류
    }

    if (month < 1 || month > 12) {
        return false;  // 월이 1~12 범위를 벗어남
    }

    int daysInMonth[] = {0, 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 
                         31, 31, 30, 31, 30, 31}; // 각 월별 최대 일수

    if (day < 1 || day > daysInMonth[month]) {
        return false;  // 일(day)이 해당 월의 최대 일수를 초과
    }

    return true;
}

void BitcoinExchange::processInputFile(const std::string &inputFile) const {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return;
    }

    std::string line;
    std::getline(file, line);
    if (!(line == "date | value")) {
        std::cerr << "Error" << std::endl;
        file.close();
        return;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, separator, valueStr;
        
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

            // 📌 날짜 형식 검증 추가
            if (!isValidDate(date)) {
                std::cerr << "Error: invalid date => " << date << "\n";
                continue;
            }

            char* endPtr;
            double value = std::strtod(valueStr.c_str(), &endPtr);
            
            if (*endPtr != '\0') {
                std::cerr << "Error: bad input => " << line << "\n";
                continue;
            }

            if (value < 0) {
                std::cerr << "Error: not a positive number.\n";
                continue;
            }
            if (value > 1000) {
                std::cerr << "Error: too large a number.\n";
                continue;
            }

            double rate = getClosestRate(date);
            if (rate == 0.0) {
                std::cerr << "Error: no valid exchange rate found for " << date << "\n";
                continue;
            }

            std::cout << date << " => " << value << " = " << value * rate << "\n";
        } else {
            std::cerr << "Error: bad input => " << line << "\n";
        }
    }

    file.close();
}

// 생성자
BitcoinExchange::BitcoinExchange(const std::string &dbFile) {
    std::ifstream file(dbFile);
    if (!file.is_open()) {
        throw Error();
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, value;
        if (std::getline(ss, date, ',') && std::getline(ss, value)) {
            data[date] = std::strtod(value.c_str(), NULL);
        }
    }
}

// getClosestRate 함수
double BitcoinExchange::getClosestRate(const std::string &date) const {
    if (data.empty()) {
        return 0.0;
    }
    
    std::map<std::string, double>::const_iterator it = data.upper_bound(date);
    if (it == data.begin()) {
        return 0.0;
    }
    --it;
    return it->second;
}

const char* BitcoinExchange::Error::what() const throw() {
    return "Error";
}
