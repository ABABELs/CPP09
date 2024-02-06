/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:42:01 by aabel             #+#    #+#             */
/*   Updated: 2024/02/06 13:37:16 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    RPN(std::string str)
{
    std::stack<double> stack;
    std::stringstream ss(str);
    
    while (ss)
    {
        std::string s;
        ss >> s;
        if (s <= "9" || s >= "0")
        {
            
            stack.push(atof(s.c_str()));
        }
        else
        {
            if (s == "+")
            {
                if (stack.size() < 2)
                    throw ErrMessage("Error: not enough values in stack for operation.");
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(a + b);
            }
            else if (s == "-")
            {
                if (stack.size() < 2)
                    throw ErrMessage("Error: not enough values in stack for operation.");
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (s == "*")
            {
                if (stack.size() < 2)
                    throw ErrMessage("Error: not enough values in stack for operation.");
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(a * b);
            }
            else if (s == "/")
            {
                if (stack.size() < 2)
                    throw ErrMessage("Error: not enough values in stack for operation.");
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
            else if (s == "%")
            {
                if (stack.size() < 2)
                    throw ErrMessage("Error: not enough values in stack for operation.");
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(fmod(b, a));
            }
            else
                throw ErrMessage("Error: invalid operation.");
        }
    }
    std::cout << stack.top() << std::endl;
}