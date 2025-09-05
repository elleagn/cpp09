/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:11:24 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 14:22:15 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stddef.h>
#include <algorithm>
#include <iostream>
#include <deque>

#include "Number.hpp"

class PmergeMeV: public std::vector<Number> {


    private:

        std::vector<size_t> jacobsthal;
        size_t              comparisons;
        size_t              orderMax;

        void renumber(std::vector<Number>& pending, size_t order);
        size_t findUpperIndex(size_t k, size_t indexMax, size_t order);
        void                binaryInsert(Number nb, size_t a, size_t b);

    public:

        PmergeMeV();
        PmergeMeV(const PmergeMeV& src);
        PmergeMeV(const std::vector<Number>& values);
        ~PmergeMeV();

        PmergeMeV& operator=(const PmergeMeV& src);

        std::vector<Number> extractPending();
        void                merge(std::vector<Number>& pending, size_t order);

        bool    is_sorted() const;
        size_t  getComparisons() const;

};

class PmergeMeD: public std::deque<Number> {


    private:

        std::deque<size_t>  jacobsthal;
        size_t              comparisons;
        size_t              orderMax;

        void renumber(std::deque<Number>& pending, size_t order);
        size_t findUpperIndex(size_t k, size_t indexMax, size_t order);
        void                binaryInsert(Number nb, size_t a, size_t b);


    public:

        PmergeMeD();
        PmergeMeD(const PmergeMeD& src);
        PmergeMeD(const std::deque<Number>& values);
        ~PmergeMeD();

        PmergeMeD& operator=(const PmergeMeD& src);

        std::deque<Number> extractPending();
        void                merge(std::deque<Number>& pending, size_t order);

        bool    is_sorted() const;
        size_t  getComparisons() const;

};
