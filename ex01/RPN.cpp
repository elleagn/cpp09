/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:59:40 by gozon             #+#    #+#             */
/*   Updated: 2025/09/08 11:12:51 by gozon            ###   ########.fr       */
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
    return (*this);
}

bool isNumber(std::string str) {
    for (size_t i = 0; i < str.size(); i++) {
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

bool RPN::treatOperator(std::string op) {

    if (pile.size() < 2)
        return (false);

    int a = pile.top();
    pile.pop();
    int b = pile.top();
    pile.pop();

    if (op == "+")
        pile.push(a + b);
    else if (op == "-")
        pile.push(b - a);
    else if (op == "*")
        pile.push(b * a);
    else if (a == 0 || op != "/")
        return (false);
    else
        pile.push(b / a);

    return (true);

}

void RPN::calculate(std::string expr) {

    std::string current;
    size_t space;

    for (size_t i = expr.find_first_not_of(' '); i < expr.size(); i = expr.find_first_not_of(' ', i)) {

        space = std::min (expr.find_first_of(' ', i), expr.size());
        current = expr.substr(i, space - i);
        if (isNumber(current))
            pile.push(atoi(current.c_str()));
        else if (!treatOperator(current)) {
            std::cerr << "Error" << std::endl;
            return ;
        }
        i = space;
    }
    if (pile.size() != 1)
        std::cerr << "Error" << std::endl;
    else
        std::cout << pile.top() << std::endl;
    return ;

}
