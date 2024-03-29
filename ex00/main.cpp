/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:50:40 by aabel             #+#    #+#             */
/*   Updated: 2024/02/05 17:25:51 by babels           ###   ########.fr       */
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
    std::map<std::string, double> mapcsv;
    makemap(mapcsv);
    // printmap(mapcsv);
    Gotoinput(argv[1], mapcsv);
    return (0);
}