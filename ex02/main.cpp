/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:50:14 by aabel             #+#    #+#             */
/*   Updated: 2024/02/08 12:41:13 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: wrong number of arguments." << std::endl;
        return (1);
    }
    try
    {
        PmergeMevector(argv);
        // PmergeMedeque(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
};