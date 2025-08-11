/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:55:02 by gozon             #+#    #+#             */
/*   Updated: 2025/08/11 16:39:38 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {

    private:
        class Date;
        std::map <Date, int> database;

        BitcoinExchange();

        void convertLine(Date date, int value);

    public:
        BitcoinExchange(std::string file);
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& src);

        void exchange(std::string file);


};

class BitcoinExchange::Date {

    private:
        int year;
        int month;
        int day;

        Date();

    public:
        Date(std::string date);
        Date(const Date& src);
        ~Date();

        Date& operator=(const Date& src);
        bool operator<(const Date& comp);

};

#endif
