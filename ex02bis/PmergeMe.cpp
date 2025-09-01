/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:51:47 by gozon             #+#    #+#             */
/*   Updated: 2025/09/01 09:50:01 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& src) {

    assign(src.begin(), src.end());

}

PmergeMe::PmergeMe(const std::vector<Number>& values) {

    assign(values.begin(), values.end());

}

PmergeMe::~PmergeMe() {

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {

    assign(src.begin(), src.end());

}

std::vector<Number> PmergeMe::extractPending() {

    std::vector<Number> pending;
    Number              nextB;
    size_t              index = 0;
    bool                leftover = size() / 2;

    for (PmergeMe::iterator it = begin(); it != end() && it + 1 != end(); it = it++) {

        if ((*it).value < (*(it + 1)). value) {
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
}
