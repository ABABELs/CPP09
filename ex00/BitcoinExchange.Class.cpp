/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:14:39 by aabel             #+#    #+#             */
/*   Updated: 2024/02/01 15:49:55 by aabel            ###   ########.fr       */
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
            if (Pipepos == std::string::npos)
            {
                throw Badinput();
                key = line.substr(0, line.find('\n'));
                value = "0";
                map.insert(std::pair<std::string, double>(key, atof(value.c_str())));
                continue;
            }
            else
            {
                key = line.substr(0, Pipepos);
                value = line.substr(line.find('|') + 1, line.find('\n'));
                // value = line.substr(Pipepos + 1, line.find('\n'));
                map.insert(std::pair<std::string, double>(key, atof(value.c_str())));
            }
        }
        catch(Badinput &e)
        {
            std::cout << e.what() << std::endl;
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