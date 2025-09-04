/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:10:10 by gozon             #+#    #+#             */
/*   Updated: 2025/09/04 08:56:00 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

void sort(PmergeMe& values, size_t order) {

    if (values.size() == 1)
        return ;
    std::vector<Number> pending = values.extractPending();
    sort(values, order + 1);
    values.merge(pending, order);

}

int main(void) {
    std::vector<Number> vect;
    Number num;

    for (int i = 0; i < 100; i++) {
        num.setValue(i);
        vect.insert(vect.end(), num);
    }

    std::random_shuffle(vect.begin(), vect.end());

    std::cout << "Shuffled" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << vect[i].getValue() << " ";
    }
    std::cout << std::endl;

    PmergeMe thing(vect);
    try {
        sort(thing, 0);
    }
    catch (std::exception& e) {
        return (1);
    }
    if (thing.is_sorted())
        std::cout << "Sorted ok" << std::endl;
    else
        std::cout << "Sorted ko" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << thing[i].getValue() << " ";
    }
    std::cout << std::endl;
}
