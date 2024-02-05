/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:14:39 by aabel             #+#    #+#             */
/*   Updated: 2024/02/05 17:33:59 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.Class.hpp"

void	makemap(std::map<std::string, double>& map)
{
    std::string line;
    std::string key;
    std::string value;
    std::ifstream file("data.csv");
    while (std::getline(file, line))
    {
        key = line.substr(0, line.find(','));
        value = line.substr(line.find(',') + 1, line.find('\n'));
        map.insert(std::pair<std::string, double>(key, atof(value.c_str())));
    }
}

void    printmap(std::map<std::string, double>& map)
{
    std::map<std::string, double>::iterator it;
    for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " | " << it->second << '\n';
    }
}

void    Gotoinput(const char *filesource, std::map<std::string, double>& map)
{
    std::string date;
    std::string value;
    std::string line;
    std::ifstream file(filesource);

    if (!file.is_open())
    {
        throw Notopen();
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        try
        {
            if (line.find('|') == line.npos)
                throw Badinput();
            date = line.substr(0, line.find('|'));
            value = line.substr(line.find('|') + 1, line.find('\n'));
            // std::cout << date << " | " << value << std::endl;
            Checkdate(date);
            Checkvalue(value);
            date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
            value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
            FindInBase(map, date, value);
        }
        catch (Badinput &e)
        {
            std::cerr << e.what() << line << std::endl;
        }
        catch (ErrMessage &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void    Checkdate(std::string &date)
{
    float		year;
	float		month;
	float		day;
	std::string	save = date;

	year = atof(date.c_str());
	if (date.find("-") == date.npos || year < 2009 || year > 2023)
		throw ErrMessage("Invalid date !");
	date.erase(0, date.find("-") + 1);
	month = atof(date.c_str());
	if (date.find("-") == date.npos || month < 1 || month > 12)
		throw ErrMessage("Invalid date !");
	date.erase(0, date.find("-") + 1);
	day = atof(date.c_str());
	if (day < 1 || day > 31)
		throw ErrMessage("Invalid date !");
	date = save;
}

void    Checkvalue(std::string &value)
{
    for (int i = 0; value[i]; i++)
		if ((value[i] < '0' || value[i] > '9') && value[i] != ' '
			&& value[i] != '-' && value[i] != '+' && value[i] != '.')
			throw ErrMessage("Error: value is not a number !");
	if (atof(value.c_str()) < 0)
		throw ErrMessage("Error: not a positive number.");
	if (atof(value.c_str()) > 1000)
		throw ErrMessage("Error: too large number.");
}

void    FindInBase(std::map<std::string, double> &map, std::string &date, std::string &value)
{
    std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator itprev;

    for (it = map.begin(); it != map.end(); ++it)
    {
        if (it->first == date)
		{
			std::cout << date << " => " << atof(value.c_str()) << " = " << atof(value.c_str()) * it->second << std::endl;
			break ;
		}
		if (it->first > date)
		{
			std::cout << date << " => " << atof(value.c_str()) << " = " << atof(value.c_str()) * itprev->second << std::endl;
			break ;
		}
        itprev = it;
    }
}