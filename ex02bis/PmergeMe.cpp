/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:51:47 by gozon             #+#    #+#             */
/*   Updated: 2025/09/01 09:06:34 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): order(0) {

}

PmergeMe::PmergeMe(const PmergeMe& src): order(src.order) {

    assign(src.begin(), src.end());

}

PmergeMe::PmergeMe(const std::vector<Number>& values, size_t order): order(order) {

    assign(values.begin(), values.end());

}

PmergeMe::~PmergeMe() {

}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {

    assign(src.begin(), src.end());
    order = src.order;

}
