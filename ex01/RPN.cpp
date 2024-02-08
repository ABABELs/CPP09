/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:42:01 by aabel             #+#    #+#             */
/*   Updated: 2024/02/07 14:48:23 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    RPN(std::string str)
{
    std::stack<double> stack;
    std::stringstream ss(str);
    
    if (Greatquantity(str) == false)
        return;
    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '%')
    {
        throw ErrMessage("Error: expression start with operator.");
        return;
    }
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
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(a + b);
            }
            else if (s == "-")
            {
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (s == "*")
            {
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                stack.pop();
                stack.push(a * b);
            }
            else if (s == "/")
            {
                double a = stack.top();
                stack.pop();
                double b = stack.top();
                if (a == 0)
                {
                    throw ErrMessage("Error: division by zero.");
                    return;
                }
                stack.pop();
                stack.push(b / a);
            }
            else if (s == "%")
            {
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
    
    if (atoi(s.c_str()) > 10 || atoi(s.c_str()) < 0)
    {
        return false;
    }
    else if (std::isdigit(s[0]) == false && s[0] != '.')
    {
        return false;
    }
    return true;
}

bool    Greatquantity(const std::string& str)
{
    std::stringstream ss(str);
    int i = 0;
    int j = 0;
    while (ss)
    {
        std::string s;
        ss >> s;
        if (is_number(s) == true)
            i++;
        else if (s == "+" || s == "-" || s == "*" || s == "/" || s == "%")
            j++;
    }
    if (i - j != 1)
    {
        throw ErrMessage("Error: invalid expression.");
        return false;
    }
    return true;
}