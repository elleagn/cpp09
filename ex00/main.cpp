/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:43:37 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 13:15:43 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {

    if (ac != 2) {
        std::cout << "Error: wrong number of arguments." << std::endl;
        return (1);
    }

    BitcoinExchange btc("data.csv");
    std::string line;
    std::ifstream input(av[1]);

    if (!input.is_open()) {
        std::cout << "Error: could not open input file" << std::endl;
        return (1);
    }

    std::getline(input, line);
    while (std::getline(input, line)) {
        btc.exchange(line);
    }
    if (input.bad()) {
        std::cout << "Error: error reading input." << std::endl;
    }
    input.close();
    return (0);

}
