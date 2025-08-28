/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:59:40 by gozon             #+#    #+#             */
/*   Updated: 2025/08/28 10:00:28 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {

}

RPN::RPN(const RPN& src): pile(src.pile) {

}

RPN::~RPN() {

}

RPN& RPN::operator=(const RPN& src) {
    pile = src.pile;
}

bool isNumber(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool isOperator(std::string str) {

    std::string ops = "+ - / *";

    if (str.size() != 1)
        return (false);
    if (ops.find_first_not_of(str[0]) == std::string::npos)
        return (true);
    return (false);
}

bool RPN::treatOperator(char op) {

    if (pile.size() < 2)
    {
        std::cerr << "Invalid expression: not enough numbers." << std::endl;
        return (false);
    }

    int a = pile.top();
    pile.pop();
    int b = pile.top();
    pile.pop();

    if (op == '+')
        pile.push(a + b);
    else if (op == '-')
        pile.push(b - a);
    else if (op == '*')
        pile.push(b * a);
    else if (a == 0) {
        std::cerr << "Error: division by 0." << std::endl;
        return (false);
    }
    else
        pile.push(b / a);

    return (true);

}

void RPN::calculate(std::string expr) {

    std::string::iterator it = expr.begin();

    

}
