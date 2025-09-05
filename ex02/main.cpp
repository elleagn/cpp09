/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:10:10 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 10:49:20 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <climits>

void sort(PmergeMeV& values, size_t order) {

    if (values.size() == 1)
        return ;
    std::vector<Number> pending = values.extractPending();
    sort(values, order + 1);
    values.merge(pending, order);

}

void sort(PmergeMeD& values, size_t order) {

    if (values.size() == 1)
        return ;
    std::deque<Number> pending = values.extractPending();
    sort(values, order + 1);
    values.merge(pending, order);

}

std::vector<Number> parseValues(int ac, char **av) {

    std::vector<Number> values;
    float               nbFloat;
    char*               end;

    for (int i = 1; i < ac; i++) {
        nbFloat = strtof(av[i], &end);
        if (*end != 0 || !std::isfinite(nbFloat) || nbFloat < 0
            || nbFloat > (float)INT_MAX || roundf(nbFloat) != nbFloat)
            throw std::invalid_argument("Invalid argument.");
        values.insert(values.end(), Number(roundf(nbFloat), (ac - 1) / 2));
    }

    return (values);
}

int main(int ac, char **av) {
    std::vector<Number> vect;
    size_t size;

    if (ac < 2) {
        std::cerr << "Error: not enough arguments" << std::endl;
        return (1);
    }

    try {
        vect = parseValues(ac, av);
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    size = vect.size();

    std::cout << "Before: ";
    for (size_t i = 0; i < size; i++) {
        std::cout << vect[i].getValue() << " ";
    }
    std::cout << std::endl;

    clock_t c_start;
    clock_t c_end;
    PmergeMeV thing(vect);
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
    for (size_t i = 0; i < size; i++) {
        std::cout << thing[i].getValue() << " ";
    }
    std::cout <<std::endl;

    std::cout   << std::fixed << std::setprecision(3) << "Time to sort "
                << size <<" elements with std::vector: "
                << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << "us" << std::endl;

    std::deque<Number> valuesD;
    valuesD.assign(vect.begin(), vect.end());
    PmergeMeD thingD(valuesD);
    try {
        c_start = clock();
        sort(thingD, 0);
        c_end = clock();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    if (!thingD.is_sorted()) {
        std::cout << "Error: sequence is not sorted." << std::endl;
        return (1);
    }
    std::cout   << std::fixed << std::setprecision(3) << "Time to sort "
                << size <<" elements with std::deque: "
                << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << "us" << std::endl;
    return (0);
}
