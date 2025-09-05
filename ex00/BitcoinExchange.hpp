/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:55:02 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 11:24:30 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cmath>

class BitcoinExchange {

    private:
        std::map <std::string, double> database;

        BitcoinExchange();
        bool checkDateFormat(std::string date) const;

        static std::string currentDate;

    public:
        BitcoinExchange(std::string data);
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& src);

        void exchange(std::string line)const;
        void printDatabase() const;


};

#endif
