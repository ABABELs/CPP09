/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:50:40 by aabel             #+#    #+#             */
/*   Updated: 2024/02/01 15:38:17 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.Class.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./bitcoin [inputfile]" << std::endl;
        return (0);
    }
    // std::map<std::string, double> mapcsv;
    // makemap(mapcsv);
    // printmap(mapcsv);
    std::map<std::string, double> mapinput;
    makeinput(argv[1], mapinput);
    printinput(mapinput);
    return (0);
}