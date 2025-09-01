/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:11:24 by gozon             #+#    #+#             */
/*   Updated: 2025/09/01 08:59:38 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stddef.h>

struct Number {

    unsigned int        value;
    std::vector<bool>   ab;
    std::vector<size_t> index;

};

class PmergeMe: public std::vector<Number> {

    private:
        size_t              order;

    public:

        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe(const std::vector<Number>& values, size_t order);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& src);

};
