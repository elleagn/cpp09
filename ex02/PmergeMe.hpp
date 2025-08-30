/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:24:19 by gozon             #+#    #+#             */
/*   Updated: 2025/08/30 14:14:48 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class PmergeMe {

    private:
        std::vector<int> vect;
        int elementSize;
        int size;

        std::vector<int> extractLast();

    public:
        PmergeMe();
        PmergeMe(std::vector<int> vect, int order);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe();

        PmergeMe&   operator=(const PmergeMe& src);
        int         operator[](int i) const;

        void swap(int i, int j);
        std::vector<int> sort();

};
