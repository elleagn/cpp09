/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:54:36 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 13:58:06 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isLeapYear(int year) {

    // year not divisible by 4
    if (year % 4)
        return (false);

    // year divisible by 4 but not by 100
    if (year % 100)
        return (true);

    // year divisible by 100 but not by 400
    if (year % 400)
        return (false);

    return (true);

}

std::string getCurrentDate() {
    time_t now = time(NULL);
    tm* gmtNow = gmtime(&now);
    std::stringstream date;

    date    << gmtNow->tm_year + 1900 << "-"
            << std::setfill('0') << std::setw(2) << gmtNow->tm_mon + 1 << "-"
            << std::setfill('0') << std::setw(2) << gmtNow->tm_mday;

    return (date.str());

}

std::string BitcoinExchange::currentDate = getCurrentDate();

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string file) {

    std::ifstream data(file.c_str());
    if (!data.is_open()) {
        throw std::runtime_error("Error: Could not open database.");
    }

    std::string line;
    std::string date;
    double      value;
    char*       end;

    std::getline(data, line);
    while (std::getline(data, line)) {

        // Get the date
        date = line.substr(0, line.find(','));
        if (!checkDateFormat(date))
            throw (std::invalid_argument("Format error in database"));

        // Get the value
        value = strtod(line.substr(line.find(',') + 1).c_str(), &end);
        if (*end || !std::isfinite(value) || value < 0)
            throw (std::invalid_argument("Format error in database"));

        database[date] = value;

    }

    if (data.bad()) {
        data.close();
        throw (std::runtime_error("Error reading database"));
    }
    data.close();

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): database(src.database) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {

    database = src.database;
    return (*this);

}

void BitcoinExchange::exchange(std::string line) const {

    // Deal with cases without separator so retrieving value does not segfault
    size_t sep = line.find('|');
    if (sep > line.size() - 3) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    // Get the date
    std::string date = line.substr(0, sep - 1);
    if (!checkDateFormat(date))
        return ;

    // Get the value
    char*   end;
    double  value = strtod(line.substr(sep + 2).c_str(), &end);
    if (*end || !std::isfinite(value)) {
        std::cout << "Error: invalid value => " << line.substr(sep + 2) << std::endl;
        return ;
    }
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }

    // Print the value to the standard output
    std::map<std::string, double>::const_iterator it = database.upper_bound(date);
    it--;
    std::cout << date << " => " << value << " = " << std::setprecision(5) << value * it->second << std::endl;
}

void BitcoinExchange::printDatabase() const
{
    for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); it ++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

bool BitcoinExchange::checkDateFormat(std::string date) const{

    bool res = true;

    if (date.size() != 10)
        res = false;
    for (int i = 0; i < 10 && res; i++) {
        if ((i == 4 || i == 7) && date[i] != '-')
            res = false;
        if (i != 4 && i != 7 && !isdigit(date[i]))
            res = false;
    }
    if (!res) {
        std::cout << "Error: Invalid date format." << std::endl;
        return (false);
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        res = false;
    if (res && day == 31 && ((month % 2 == 0 && month <= 6)
            || (month % 2 == 1 && month > 7)))
        res = false;
    if (res && month == 2 && (day > 29 || (day == 29 && !isLeapYear(year) )))
        res = false;
    if (!res) {
        std::cout << "Error: date doesn't exist." << std::endl;
        return (false);
    }

    if (res && date < "2009-01-02") {
        res = false;
        std::cout << "Error: no data prior to January 2nd 2009." << std::endl;
    }

    if (res && date > currentDate) {
        std::cout << "Error: can't predict the future." << std::endl;
        res = false;
    }

    return (res);

}

