/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:55:02 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 11:01:00 by gozon            ###   ########.fr       */
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

class BitcoinExchange {

    private:
        std::map <std::string, double> database;

        BitcoinExchange();
        bool checkDateFormat(std::string date);

        static std::string currentDate;

    public:
        BitcoinExchange(std::string data);
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& src);

        void exchange(std::string file);
        void printDatabase() const;


};

#endif
