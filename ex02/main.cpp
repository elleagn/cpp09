/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:37:26 by gozon             #+#    #+#             */
/*   Updated: 2025/08/30 15:04:01 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(void) {

    std::vector<int> vect;
    for (int i = 0; i < 100; i++) {
        vect.insert(vect.begin(), i);
    }
    std::cout << "Vect beginning:";
    for (size_t i = 0; i < vect.size(); i++) {
        std::cout << " " << vect[i];
    }
    std::cout << std::endl;

    PmergeMe test(vect, 50);

    std::cout << "operator[]: " << test[0] << " " << test[1] << std::endl;

    test.sortPairs();

    vect = test.getVect();
    std::cout << "Swap:";
    for (size_t i = 0; i < vect.size(); i++) {
        std::cout << " " << vect[i];
    }
    std::cout << std::endl;

}
