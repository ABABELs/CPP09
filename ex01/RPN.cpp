/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:42:01 by aabel             #+#    #+#             */
/*   Updated: 2024/02/07 11:41:55 by aabel            ###   ########.fr       */
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
        if (is_number(s) == true)
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
        if (ss.eof() == true)
        {
            std::cout << stack.top() << std::endl;
            break;
        }
    }
}

bool    is_number(const std::string& s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (std::isdigit(s[i]) == false && s[i] != '.')
            return false;
    }
    return true;
}