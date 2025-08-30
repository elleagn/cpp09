/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:43:59 by gozon             #+#    #+#             */
/*   Updated: 2025/08/30 15:00:25 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): vect(std::vector<int>()) {

}

// maybe by reference
PmergeMe::PmergeMe(std::vector<int> vect, int elementSize): vect(vect), elementSize(elementSize) {
    size = vect.size() / elementSize;
}

PmergeMe::~PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& src): vect(src.vect), elementSize(src.elementSize) {

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {

    vect = src.vect;
    elementSize = src.elementSize;
    return (*this);
}

int PmergeMe::operator[](int i) const {

    if (i >= size)
        throw std::out_of_range("Index out of range");
    return (vect[ (i + 1) * elementSize - 1]);

}

const std::vector<int>& PmergeMe::getVect() const {
    return (vect);
}

void PmergeMe::swap(int i, int j) {

    if (i >= size)
        throw std::out_of_range("Index out of range");
    if (j >= size)
        throw std::out_of_range("Index out of range");

    for (int k = 0; k < elementSize; k++) {
        std::swap(vect[i * elementSize + k], vect[j * elementSize + k]);
    }

}

std::vector<int> PmergeMe::extractLast() {

    std::vector<int> last;

    for (int i = 0; i < elementSize; i++) {
        last.insert(last.begin(), *vect.end());
        vect.pop_back();
    }

    size--;

    return (last);
}

void PmergeMe::sortPairs() {

    for (int i = 0; i < size; i += 2) {
        if ((*this)[i] > (*this)[i + 1])
            swap(i, i + 1);
    }

}


// std::vector<int> PmergeMe::sort() {

//     std::vector<int> pending;
//     std::vector<int> leftover;

//     if (size / 2) {
//         leftover = extractLast();
//     }
//     sortPairs();
//     elementSize *= 2;
//     size /= 2;
//     sort();
//     elementSize /= 2;
//     size *= 2;

//     pending = extractPending();

//     insertPending(pending);
//     return (vect);
// }
