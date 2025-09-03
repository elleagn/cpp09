/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:41:26 by gozon             #+#    #+#             */
/*   Updated: 2025/09/03 15:01:57 by gozon            ###   ########.fr       */
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
        bool    operator<(const Number& comp) const;
        bool    operator>(const Number& comp) const;
        bool    operator<=(const Number& comp) const;
        bool    operator>=(const Number& comp) const;

        void    addLabel(char ab, size_t index, size_t order = std::string::npos);

        void print(size_t order) const;

};

