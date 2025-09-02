/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:11:24 by gozon             #+#    #+#             */
/*   Updated: 2025/09/02 12:59:36 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stddef.h>
#include <algorithm>
#include <iostream>

class Number {

    public:
        unsigned int        value;
        std::vector<bool>   ab;
        std::vector<size_t> index;
        void print(size_t order) const;

};

class PmergeMe: public std::vector<Number> {


    private:
        void renumber(std::vector<Number>& pending, size_t order);
        size_t findUpperIndex(size_t k, size_t indexMax, size_t order);
        std::vector<size_t> jacobsthal;

    public:

        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe(const std::vector<Number>& values);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& src);

        std::vector<Number> extractPending();
        void                merge(std::vector<Number>& pending, size_t order);
        void                binaryInsert(Number nb, size_t a, size_t b);

};
