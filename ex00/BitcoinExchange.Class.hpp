/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:09:29 by aabel             #+#    #+#             */
/*   Updated: 2024/02/05 17:29:53 by babels           ###   ########.fr       */
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
			return ("Error: Bad input => ");
		}
};

class Notopen : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Error: could not open file.");
		}
};

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

void	makemap(std::map<std::string, double>& map);
void	printmap(std::map<std::string, double>& map);
void	Checkdate(std::string &date);
void	Checkvalue(std::string &value);
void	Gotoinput(const char *filesource, std::map<std::string, double>& map);
void	FindInBase(std::map<std::string, double>& map, std::string &date, std::string &value);

#endif