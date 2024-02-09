/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:04:01 by aabel             #+#    #+#             */
/*   Updated: 2024/02/09 11:09:20 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#include <climits>
#include <vector>
#include <deque>
#include <algorithm>



class ErrMessage : public std::exception
{
    private:
        const char *_message;
    public:
        ErrMessage(const char *_message) : _message(_message) {}
        virtual const char* what() const throw()
        {
            return _message;
        }
};

void PmergeMevector(char **argv);
void PrintVector(std::vector<unsigned int> vec);
void Mergesort(std::vector<unsigned int> &vec);

void PmergeMedeque(char *str);

#endif