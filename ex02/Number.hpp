/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:41:26 by gozon             #+#    #+#             */
/*   Updated: 2025/09/04 13:24:48 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stddef.h>
#include <iostream>

class Number {

    private:
        unsigned long   value;
        size_t          size;
        size_t          end;
        bool*           ab;
        size_t*         index;

        Number();

    public:

        Number(unsigned long value, size_t size);
        Number(const Number& src);
        ~Number();

        Number& operator=(const Number& src);
        bool    operator<(const Number& comp) const;
        bool    operator>(const Number& comp) const;
        bool    operator<=(const Number& comp) const;
        bool    operator>=(const Number& comp) const;

        void            changeLabel(char ab, size_t index, size_t order = std::string::npos);
        size_t          getIndex(size_t order) const;
        bool            isA(size_t order) const;
        unsigned long   getValue() const;
        void            setValue(unsigned long value);

        void print(size_t order) const;

};

