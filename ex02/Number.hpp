/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:41:26 by gozon             #+#    #+#             */
/*   Updated: 2025/09/05 08:45:39 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stddef.h>
#include <iostream>

class Number {

    private:
        int   value;
        size_t          size;
        size_t          end;
        bool*           ab;
        size_t*         index;

        Number();

    public:

        Number(int value, size_t size);
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
        int   getValue() const;
        void            setValue(int value);

        void print(size_t order) const;

};

