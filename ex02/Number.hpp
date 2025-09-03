/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:41:26 by gozon             #+#    #+#             */
/*   Updated: 2025/09/03 08:46:03 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stddef.h>
#include <iostream>

class Number {

    private:

    public:
        unsigned long       value;
        std::vector<bool>   ab;
        std::vector<size_t> index;

        Number();
        Number(unsigned long value);
        Number(const Number& src);
        ~Number();

        Number& operator=(const Number& src);

        void print(size_t order) const;

};

