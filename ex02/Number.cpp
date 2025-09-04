/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:45:22 by gozon             #+#    #+#             */
/*   Updated: 2025/09/04 08:55:12 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number() {}

Number::Number(unsigned long value): value(value) {}

Number::Number(const Number& src): value(src.value), ab(src.ab), index(src.index) {}

Number::~Number() {}

Number& Number::operator=(const Number& src) {

    if (this != &src) {
        value = src.value;
        ab = src.ab;
        index = src.index;
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
    if (order >= this->ab.size()) {
        this->ab.push_back(ab == 'a');
        this->index.push_back(index);
    }
    else {
        if (ab)
            this->ab[order] = (ab == 'a');
        this->index[order] = index;
    }
}

bool Number::isA(size_t order) const {
    if (order >= index.size())
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
    if (order >= index.size())
        throw std::out_of_range("getIndex: order too high");
    return (index[order]);
}
