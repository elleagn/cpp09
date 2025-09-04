/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:45:22 by gozon             #+#    #+#             */
/*   Updated: 2025/09/04 13:50:50 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number(): ab(NULL), index(NULL) {}

Number::Number(unsigned long value, size_t size): value(value), size(size) {

    ab = new bool[size];
    index = new size_t[size];
    end = 0;

}

Number::Number(const Number& src): value(src.value), size(src.size), end(src.end),
    ab(new bool[size]), index(new size_t[size]) {

    for (size_t i = 0; i < end; i++) {
        ab[i] = src.ab[i];
        index[i] = src.index[i];
    }

}

Number::~Number() {
    delete[] ab;
    delete[] index;
}

Number& Number::operator=(const Number& src) {

    if (size != src.size) {
        throw std::out_of_range("Number can't change of size");
    }
    if (this != &src) {
        end = src.end;
        value = src.value;
        for (size_t i = 0; i < end; i++) {
            ab[i] = src.ab[i];
            index[i] = src.index[i];
        }
    }

    return (*this);

}

bool Number::operator<(const Number& comp) const {
    return (value < comp.value);
}

bool Number::operator>(const Number& comp) const {
    return (value > comp.value);
}

bool Number::operator<=(const Number& comp) const {
    return (value <= comp.value);
}

bool Number::operator>=(const Number& comp) const {
    return (value >= comp.value);
}

void Number::print(size_t order) const {

    std::cout << "[" << (ab[order]==1?"a":"b") << index[order] << ": " << value << "]";

}

void    Number::changeLabel(char ab, size_t index, size_t order) {
    if (order >= end && ab) {
        if (end >= size)
            throw std::out_of_range("changeLabel: order too big");
        this->ab[end] = (ab == 'a');
        this->index[end] = index;
        end++;
    }
    else {
        if (ab)
            this->ab[order] = (ab == 'a');
        this->index[order] = index;
    }
}

bool Number::isA(size_t order) const {
    if (order >= end)
        throw std::out_of_range("isA: order too high");
    return (ab[order]);
}

void Number::setValue(unsigned long value)
{
    this->value = value;
}

unsigned long Number::getValue() const {
    return (value);
}

size_t Number::getIndex(size_t order) const {
    if (order >= end)
        throw std::out_of_range("getIndex: order too high");
    return (index[order]);
}
