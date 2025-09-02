/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:51:47 by gozon             #+#    #+#             */
/*   Updated: 2025/09/02 14:39:42 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& src) {

    assign(src.begin(), src.end());

}

PmergeMe::PmergeMe(const std::vector<Number>& values) {

    size_t valuesSize = values.size();
    size_t twoPow = 2;
    size_t tk = 1;

    std::cout << "jacobsthal:";
    while (tk <= valuesSize) {
        tk = twoPow - tk;
        std::cout << " " << tk;
        jacobsthal.insert(jacobsthal.end(), tk);
        twoPow *= 2;
    }
    std::cout << std::endl;


    assign(values.begin(), values.end());

}

PmergeMe::~PmergeMe() {

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {

    assign(src.begin(), src.end());
    return (*this);
}

std::vector<Number> PmergeMe::extractPending() {

    std::vector<Number> pending;
    Number              nextB;
    size_t              index = 0;
    bool                leftover = size() % 2;

    for (PmergeMe::iterator it = begin(); it != end() && it + 1 != end(); it++) {

        if ((*it).value < (*(it + 1)).value) {
            nextB = *it;
            it = erase(it);
        }
        else {
            nextB = *(it + 1);
            erase(it + 1);
        }
        (*it).ab.push_back(1);
        (*it).index.push_back(index);
        nextB.ab.push_back(0);
        nextB.index.push_back(index);
        pending.push_back(nextB);
        index++;
    }

    if (leftover) {

        back().ab.push_back(0);
        back().index.push_back(index);
        pending.push_back(back());
        erase(end() - 1);

    }
    std::cout << "Pending" << std::endl;
    for (size_t i = 0; i < pending.size(); i++) {
        pending[i].print(pending[i].ab.size() - 1);
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "main" << std::endl;
    for (size_t i = 0; i < size(); i++) {
        at(i).print(at(i).ab.size() - 1);
        std::cout << " ";
    }
    std::cout << std::endl;
    return (pending);
}

void PmergeMe::renumber(std::vector<Number>& pending, size_t order) {

    for (size_t i = 0; i < size(); i++) {
        pending[at(i).index[order]].index[order] = i;
        at(i).index[order] = i;
    }

    std::cout << "Pending after renumbered" << std::endl;
    for (size_t i = 0; i < pending.size(); i++) {
        pending[i].print(order);
        std::cout << " ";
    }
    std::cout << std::endl;
    Number tmp;
    for (size_t i = 0; i < pending.size(); i++) {

        if (pending[i].index[order] != i) {
            tmp = pending[i];
            pending[i] = pending[pending[i].index[order]];
            pending[pending[i].index[order]] = tmp;
        }

    }

}

void PmergeMe::binaryInsert(Number nb, size_t a, size_t b) {

    if (at(b).value <= nb.value){
        insert(end(), nb);
        return ;
    }
    while (b - a > 1) {
        if (nb.value > at(a + (b - a) / 2).value) {
            a = a + (b - a) / 2;
        }
        else
            b = a + (b - a) / 2;
    }

    insert(begin() + b, nb);

}

size_t PmergeMe::findUpperIndex(size_t k, size_t indexMax, size_t order) {

    size_t i = indexMax;

    while (!at(indexMax).ab[order] || at(indexMax).index[order] != k)
        i--;

    return (i);
}

void PmergeMe::merge(std::vector<Number>& pending, size_t order) {

    std::cout << "main before renumbered: ";
    for (size_t i = 0; i < size(); i++) {
        at(i).print(order);
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Pending before renumbered" << std::endl;
    for (size_t i = 0; i < pending.size(); i++) {
        pending[i].print(order);
        std::cout << " ";
    }
    std::cout << std::endl;
    renumber(pending, order);
    std::cout << "Pending after renumbered" << std::endl;
    for (size_t i = 0; i < pending.size(); i++) {
        pending[i].print(order);
        std::cout << " ";
    }
    std::cout << std::endl;
    size_t jacobMax = size();
    insert(begin(), pending[0]);

    for (size_t i = 1; jacobsthal[i] < jacobMax; i++) {

        size_t upperIndex = std::min(jacobsthal[i - 1] + jacobsthal[i] - 2, size());
        std::cout << "Upper index: " << upperIndex << std::endl;

        for (size_t k = std::min(jacobMax, jacobsthal[i]) - 1; k >= jacobsthal[i - 1]; k--) {

            upperIndex = findUpperIndex(k, upperIndex, order);
            binaryInsert(pending[k], 0, upperIndex);

        }

    }

    if (pending.size() > jacobMax) {
        binaryInsert(pending.back(), 0, size() - 1);
    }
}

void Number::print(size_t order) const {

    std::cout << "[" << (ab[order]==1?"a":"b") << index[order] << ": " << value << "]";

}
