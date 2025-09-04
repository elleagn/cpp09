/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:10:10 by gozon             #+#    #+#             */
/*   Updated: 2025/09/04 13:39:27 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void sort(PmergeMe& values, size_t order) {

    if (values.size() == 1)
        return ;
    std::vector<Number> pending = values.extractPending();
    sort(values, order + 1);
    values.merge(pending, order);

}

int main(int ac, char **av) {
    std::vector<Number> vect;
    int size = 1000;
    Number num(0, size / 2);

    (void)av;
    (void)ac;

    for (int i = 0; i < size; i++) {
        num.setValue(i);
        vect.insert(vect.end(), num);
    }

    std::random_shuffle(vect.begin(), vect.end());

    std::cout << "Before: ";
    for (int i = 0; i < size; i++) {
        std::cout << vect[i].getValue() << " ";
    }
    std::cout << std::endl;

    clock_t c_start;
    clock_t c_end;
    PmergeMe thing(vect);
    try {
        c_start = clock();
        sort(thing, 0);
        c_end = clock();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    if (!thing.is_sorted()) {
        std::cout << "Error: sequence is not sorted." << std::endl;
        return (1);
    }
    std::cout << "After: ";
    for (int i = 0; i < size; i++) {
        std::cout << thing[i].getValue() << " ";
    }
    std::cout <<std::endl;

    std::cout   << std::fixed << std::setprecision(6) << "Time to sort "
                << size <<" elements: "
                << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << "us" << std::endl;
    return (0);
}
