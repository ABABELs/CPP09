/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:58:44 by aabel             #+#    #+#             */
/*   Updated: 2024/02/08 14:28:06 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMevector(char **argv)
{
    std::vector<unsigned int> vec;
    for (int i = 1; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (isdigit(argv[i][j]))
                vec.push_back(atoi(argv[i]));
            else
                throw ErrMessage("Error: invalid argument.");
        }
    }
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec.size() % 2 != 0 && i == vec.size() - 1)
            break;
        else if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
    }
    std::vector<unsigned int> vec2;
    for (size_t i = 1; i < vec.size(); i += 2)
        vec2.push_back(vec[i]);
    for (size_t i = 1; i < vec.size(); i++)
        vec.erase(vec.begin() + i);
    PrintVector(vec); 
    PrintVector(vec2);
    std::sort(vec2.begin(), vec2.end());
    PrintVector(vec2);
}

void PrintVector(std::vector<unsigned int> vec)
{
    for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}