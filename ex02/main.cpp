/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:10:10 by gozon             #+#    #+#             */
/*   Updated: 2025/09/02 08:27:41 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void sort(PmergeMe& values, size_t order) {

    std::vector<Number> pending = values.extractPending();
    sort(values, order + 1);
    values.merge(pending, order);

}
