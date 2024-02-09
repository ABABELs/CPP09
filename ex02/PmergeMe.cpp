/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:58:44 by aabel             #+#    #+#             */
/*   Updated: 2024/02/09 14:12:31 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMevector(char **argv)
{
    std::vector<unsigned int> vec;
    for (int i = 1; argv[i]; i++)
    {
        bool isvalid = true;
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                isvalid = false;
                break;
            }
        }
        if (isvalid)
            vec.push_back(atoi(argv[i]));
        else
            throw ErrMessage("Invalid input");
    }
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec.size() % 2 != 0 && i == vec.size() - 1)
            break;
        else if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
    }
    PrintVector(vec);
    Mergesort(vec);
    PrintVector(vec);
}

void PrintVector(std::vector<unsigned int> vec)
{
    for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void Mergesort(std::vector<unsigned int> &vec)
{
    if (vec.size() <= 1)
        return;
    
    std::vector<unsigned int> res;
    for (size_t i = 1; i < vec.size(); i += 2)
        res.push_back(vec[i - 1]);
    std::cout << "res: ";
    PrintVector(res);
    std::cout << "vec: ";
    PrintVector(vec);
    Mergesort(res);
    
    vec = res;
}

// void    Mergesort(std::vector<unsigned int> &vec)
// {
    // if (vec.size() <= 1)
    //     return;
    // std::vector<unsigned int> left;
    // std::vector<unsigned int> right;
    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     if (i < vec.size() / 2)
    //         left.push_back(vec[i]);
    //     else if (i >= vec.size() / 2)
    //         right.push_back(vec[i]);
    // }
    // Mergesort(left);
    // Mergesort(right);
    // vec.clear();
    // while (left.size() > 0 && right.size() > 0)
    // {
    //     if (left.front() <= right.front())
    //     {
    //         vec.push_back(left.front());
    //         left.erase(left.begin());
    //     }
    //     else
    //     {
    //         vec.push_back(right.front());
    //         right.erase(right.begin());
    //     }
    // }
    // while (left.size() > 0)
    // {
    //     vec.push_back(left.front());
    //     left.erase(left.begin());
    // }
    // while (right.size() > 0)
    // {
    //     vec.push_back(right.front());
    //     right.erase(right.begin());
    // }
    // std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec));
// }