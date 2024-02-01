/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:09:29 by aabel             #+#    #+#             */
/*   Updated: 2024/02/01 15:34:45 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <string>
# include <map>
# include <algorithm>
# include <iomanip>
# include <exception>
# include <stdlib.h>

class Badinput : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Bad input file");
		}
};

class Notopen : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("File not open");
		}
};

void	makemap(std::map<std::string, double>& map);
void	printmap(std::map<std::string, double>& map);
void	makeinput(char *input, std::map<std::string, double>& map);
void	printinput(std::map<std::string, double>& map);

#endif