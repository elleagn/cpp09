/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:54:36 by gozon             #+#    #+#             */
/*   Updated: 2025/08/13 13:32:39 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int strToInt(std::string str) {

    std::stringstream tmp;
    int res;

    tmp << str;
    tmp >> res;
    return (res);

}

int strToDouble(std::string str) {

    std::stringstream tmp;
    int res;

    tmp << str;
    tmp >> res;
    return (res);

}

bool isLeapYear(int year) {

    if (year % 4)
        return (false);
    if (year % 100)
        return (true);
    if (year % 400)
        return (false);
    return (true);

}

std::string getCurrentDate() {
    time_t now = time(NULL);
    tm* gmtNow = gmtime(&now);
    std::stringstream date;

    date << gmtNow->tm_year << "-" << gmtNow->tm_mon + 1 << "-" << gmtNow->tm_mday;

    return (date.str());

}

std::string BitcoinExchange::currentDate = getCurrentDate();

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string file) {

    std::ifstream data(file);
    if (!data.is_open()) {
        throw std::runtime_error("Error: Could not open database.");
    }

    std::string line;
    std::getline(data, line);

    
}

bool BitcoinExchange::checkDateFormat(std::string date) {

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
    }

    int year = strToInt(date.substr(0, 4));
    int month = strToInt(date.substr(5, 2));
    int day = strToInt(date.substr(8, 2));
    if (month < 1 || month > 12 || day < 1 || day > 31)
        res = false;
    if (res && day == 31 && ((month % 2 == 0 && month <= 6)
            || (month % 2 == 1 && month > 7)))
        res = false;
    if (res && month == 2 && (day > 29 || (day == 29 && !isLeapYear(year) )))
        res = false;
    if (!res) {
        std::cout << "Error: date doesn't exist." << std::endl;
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
