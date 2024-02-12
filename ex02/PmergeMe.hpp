/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:04:01 by aabel             #+#    #+#             */
/*   Updated: 2024/02/12 15:49:47 by babels           ###   ########.fr       */
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

bool	isnumbers(std::string numbers);
void	printargv(char **argv);
void	checknumbers(char **argv);
void	sortmycontainers(int argc, char **argv);

void	printvec(std::vector<unsigned int> vec);
void    sortvec(std::vector<unsigned int> &vec);
size_t	binarySearchVector(std::vector<unsigned int> res, unsigned int nb);

void	sortdeque(std::deque<unsigned int> &deq);
size_t	binarySearchDeque(std::deque<unsigned int> res, unsigned int nb);
void	printdeq(std::deque<unsigned int> deq);

#endif