/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:47:50 by gozon             #+#    #+#             */
/*   Updated: 2025/08/28 09:20:13 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <functional>

class RPN {

    private:
        std::stack<int> pile;

        bool treatOperator(char op);

    public:
        RPN();
        RPN(const RPN& src);
        ~RPN();

        RPN& operator=(const RPN& src);

        void calculate(std::string expr);

};
