/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:10:10 by gozon             #+#    #+#             */
/*   Updated: 2025/09/03 11:38:06 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

void sort(PmergeMe& values, size_t order) {

    std::cout << "In sort, order: " << order << std::endl;
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
        num.value = i;
        vect.insert(vect.end(), num);
    }

    std::random_shuffle(vect.begin(), vect.end());
    for (int i = 0; i < 100; i++) {
        std::cout << vect[i].value << " ";
    }
    std::cout << std::endl;

    std::cout << "Shuffled" << std::endl;
    PmergeMe thing(vect);
    try {
        sort(thing, 0);
    }
    catch (std::exception& e) {
        return (1);
    }
    std::cout << "Sorted" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << thing[i].value << " ";
    }
    std::cout << std::endl;
}
