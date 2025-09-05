/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:51:47 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 14:57:26 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeV::PmergeMeV() {

}

PmergeMeV::PmergeMeV(const PmergeMeV& src): jacobsthal(src.jacobsthal),
    comparisons(src.comparisons), orderMax(src.orderMax) {

    assign(src.begin(), src.end());

}

PmergeMeV::PmergeMeV(const std::vector<Number>& values): comparisons(0) {

    orderMax = values.size() / 2;
    size_t twoPow = 2;
    size_t tk = 1;

    while (tk <= orderMax) {
        tk = twoPow - tk;
        jacobsthal.insert(jacobsthal.end(), tk);
        twoPow *= 2;
    }

    assign(values.begin(), values.end());

}

PmergeMeV::~PmergeMeV() {

}

PmergeMeV& PmergeMeV::operator=(const PmergeMeV& src) {

    assign(src.begin(), src.end());
    jacobsthal = src.jacobsthal;
    comparisons = src.comparisons;
    orderMax = src.orderMax;
    return (*this);
}

std::vector<Number> PmergeMeV::extractPending() {

    std::vector<Number> pending;
    Number              nextB(0, orderMax);
    size_t              index = 0;
    bool                leftover = size() % 2;

    for (PmergeMeV::iterator it = begin(); it != end() && it + 1 != end(); it++) {

        comparisons++;
        if (*it < *(it + 1)) {
            nextB = *it;
            it = erase(it);
        }
        else {
            nextB = *(it + 1);
            erase(it + 1);
        }
        (*it).changeLabel('a', index);
        nextB.changeLabel('b', index);
        pending.push_back(nextB);
        index++;
    }

    if (leftover) {

        back().changeLabel('b', index);
        pending.push_back(back());
        erase(end() - 1);

    }
    return (pending);
}

void PmergeMeV::renumber(std::vector<Number>& pending, size_t order) {

    for (size_t i = 0; i < size(); i++) {
        pending[at(i).getIndex(order)].changeLabel(0, i, order);
        at(i).changeLabel(0, i, order);
    }

    Number tmp(0, orderMax);
    for (size_t i = 0; i < pending.size(); i++) {

        while (pending[i].getIndex(order) != i) {
            std::swap(pending[i], pending[pending[i].getIndex(order)]);
        }

    }

}

void PmergeMeV::binaryInsert(Number nb, size_t a, size_t b) {

    comparisons++;
    if (at(b) <= nb){
        insert(end(), nb);
        return ;
    }
    comparisons++;
    if (at(a) >= nb){
        insert(begin(), nb);
        return ;
    }
    while (b - a > 1) {
        comparisons++;
        if (nb > at(a + (b - a) / 2)) {
            a = a + (b - a) / 2;
        }
        else
            b = a + (b - a) / 2;
    }

    insert(begin() + b, nb);

}

size_t PmergeMeV::findUpperIndex(size_t k, size_t indexMax, size_t order) {

    size_t i = indexMax;

    while (!at(i).isA(order) || at(i).getIndex(order) != k)
        i--;

    return (i);
}

void PmergeMeV::merge(std::vector<Number>& pending, size_t order) {

    renumber(pending, order);
    size_t jacobMax = size();
    insert(begin(), pending[0]);

    for (size_t i = 1; jacobsthal[i - 1] < jacobMax; i++) {

        size_t upperIndex = std::min(jacobsthal[i - 1] + jacobsthal[i], size()) - 1;

        for (size_t k = std::min(jacobMax, jacobsthal[i]) - 1; k >= jacobsthal[i - 1]; k--) {

            upperIndex = findUpperIndex(k, upperIndex, order);
            binaryInsert(pending[k], 0, upperIndex);

        }

    }

    if (pending.size() > jacobMax) {
        binaryInsert(pending.back(), 0, size() - 1);
    }
}

bool PmergeMeV::is_sorted() const {
    for (size_t i = 0; i + 1 < size(); i++) {
        if (at(i) > at(i + 1))
            return (false);
    }
    return (true);
}

size_t PmergeMeV::getComparisons() const {
    return (comparisons);
}
