/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:14:39 by aabel             #+#    #+#             */
/*   Updated: 2024/02/05 11:32:57 by aabel            ###   ########.fr       */
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

void makeinput(char *input, std::map<std::string, double>& map)
{
    std::string line;
    std::string key;
    std::string value;
    std::string date;
    std::ifstream file(input);

    if (!file.is_open())
    {
        throw Notopen();
    }
    while (std::getline(file, line))
    {
        try
        {
            std::size_t Pipepos = line.find('|');
            date = line.substr(0, Pipepos);
            if (Checkinput(date) == false)
                continue;
            else if (Pipepos == std::string::npos)
            {
                key = line.substr(0, line.find('\n'));
                value = "0";
                map.insert(std::pair<std::string, double>(key, atof(value.c_str())));
                throw Badinput();
                continue;
            }
            else
            {
                key = line.substr(0, Pipepos);
                value = line.substr(line.find('|') + 1, line.find('\n'));
                map.insert(std::pair<std::string, double>(key, atof(value.c_str())));
            }
        }
        catch(Badinput &e)
        {
            std::cout << e.what();
            std::cout << key << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
}

void    printinput(std::map<std::string, double>& map)
{
    std::map<std::string, double>::iterator it;
    for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << "|" << it->second << '\n';
    }
}

bool    Checkinput(std::string date)
{
    float years;
    float months;
    float days;
    
    years = std::atof(date.c_str());
    if (date.find('-') == date.npos || years < 2000 || years > 2024)
    {
        throw ErrMessage("Not a valid year");
        return false;
    }
    date.erase(0, date.find('-') + 1);
    months = std::atof(date.c_str());
    if (date.find('-') == date.npos || months < 1 || months > 12)
    {
        throw ErrMessage("Not a valid month");
        return false;
    }
    date.erase(0, date.find('-') + 1);
    days = std::atof(date.c_str());
    if (date.find('-') != date.npos || days < 1 || days > 31)
    {
        throw ErrMessage("Not a valid day");
        return false;
    }

    return true;
}