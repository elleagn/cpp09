/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:11:24 by gozon             #+#    #+#             */
/*   Updated: 2025/09/01 09:35:24 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stddef.h>
#include <algorithm>

struct Number {

    unsigned int        value;
    std::vector<bool>   ab;
    std::vector<size_t> index;

};

class PmergeMe: public std::vector<Number> {


    public:

        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe(const std::vector<Number>& values);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& src);

        std::vector<Number> extractPending();

};
