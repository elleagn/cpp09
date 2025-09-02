/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:10:10 by gozon             #+#    #+#             */
/*   Updated: 2025/09/02 11:16:19 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

void sort(PmergeMe& values, size_t order) {

    std::cout << "In sort, order: " << order << std::endl;
    if (values.size() == 1)
        return ;
    std::cout << "Size before pending extract: " << values.size() << std::endl;
    std::vector<Number> pending = values.extractPending();
    std::cout << "Size after pending extract: " << values.size() << std::endl;
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
    std::cout << "size beginning: " << thing.size() << std::endl;
    sort(thing, 0);
    std::cout << "Sorted" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << thing[i].value << " ";
    }
    std::cout << std::endl;
}
