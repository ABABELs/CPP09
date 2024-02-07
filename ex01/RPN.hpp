/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:36:36 by aabel             #+#    #+#             */
/*   Updated: 2024/02/07 11:37:34 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <exception>
#include <cctype>

class ErrMessage : public std::exception
{
	private:
		const char *_message;
	public:
		ErrMessage(const char *_message) : _message(_message) {}
		virtual const char* what() const throw()
		{
			return _message;
		}
};

void RPN(std::string str);
bool is_number(const std::string& s);

#endif