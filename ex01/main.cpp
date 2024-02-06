/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:37:32 by aabel             #+#    #+#             */
/*   Updated: 2024/02/06 12:07:38 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cerr << "Error: too many arguments." << std::endl;
        return 1;
    }
    RPN(argv[1]);
    return 0;
}