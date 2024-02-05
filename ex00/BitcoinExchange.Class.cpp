/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:14:39 by aabel             #+#    #+#             */
/*   Updated: 2024/02/05 14:42:11 by aabel            ###   ########.fr       */
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

void    Gotoinput(std::string filename, std::map<std::string, double>& map)
{
    
}

void    Checkinput(std::string date)
{
    float years;
    float months;
    float days;
    
    years = std::atoi(date.c_str());
    if (date.find('-') == date.npos || years < 2000 || years > 2024)
    {
        throw ErrMessage("Not a valid year");
    }
    date.erase(0, date.find('-') + 1);
    months = std::atoi(date.c_str());
    if (date.find('-') == date.npos || months < 1 || months > 12)
    {
        throw ErrMessage("Not a valid month");
    }
    date.erase(0, date.find('-') + 1);
    days = std::atoi(date.c_str());
    if (date.find('-') != date.npos || days < 1 || days > 31)
    {
        throw ErrMessage("Not a valid day");
    }
}