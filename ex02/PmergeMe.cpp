/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:58:44 by aabel             #+#    #+#             */
/*   Updated: 2024/02/12 16:18:07 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// \v/ fonction start \v/ //
void    checknumbers(char **argv)
{
    int i = 0;
	while (argv[++i])
        if (!isnumbers(argv[i]))
            throw ErrMessage("Not a good input");
}

bool    isnumbers(std::string numbers)
{
    std::string::iterator ite = numbers.end();
    for (std::string::iterator it = numbers.begin(); it != ite; it++)
	{
		if (!isdigit(*it))
			return (0);
	}
	return (1);
}

void	printargv(char **argv)
{
	std::cout << "argv = ";
	for (int i = 1; argv[i]; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
}
// /^\ check fonction end /^\ //


// \v/ vector fonction start \v/ //
void	printvec(std::vector<unsigned int> vec)
{
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

size_t	binarySearchVector(std::vector<unsigned int> res, unsigned int nb)
{
	if (res[res.size() - 1] < nb)
		return (res.size());
	if (res[0] > nb)
		return (0);
	size_t	first = 0;
	size_t	last = res.size();
	size_t	mid = (first + (last - first) / 2);
	while (first != mid && mid != last)
	{
		if (nb == res[mid])
			return (mid);
		if (nb < res[mid])
			last = mid;
		else if (nb > res[mid])
			first = mid;
		mid = (first + (last - first) / 2);
	}
	return (mid + 1);
}

void	sortvec(std::vector<unsigned int> &vec)
{
	if (vec.size() <= 1)
		return ;
	
	for (size_t j = 0; j + 1 < vec.size(); j += 2)
	{
		if (vec[j] < vec[j + 1])
			std::swap(vec[j], vec[j + 1]);
	}
	std::vector<unsigned int> res;
	for (size_t i = 1; i + 1 <= vec.size(); i += 2)
		res.push_back(vec[i]);
	sortvec(res);
	for (size_t u = 0; u < vec.size(); u += 2)
		res.insert(res.begin() + binarySearchVector(res, vec[u]), vec[u]);
	vec = res;
}
// /^\ vector fonction end /^\ //


// \v/ deque fonction start \v/ //
void	printdeq(std::deque<unsigned int> deq)
{
	for (std::deque<unsigned int>::iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	sortdeque(std::deque<unsigned int> &deq)
{
	if (deq.size() <= 1)
		return ;
	
	for (size_t j = 0; j + 1 < deq.size(); j += 2)
	{
		if (deq[j] < deq[j + 1])
			std::swap(deq[j], deq[j + 1]);
	}
	std::deque<unsigned int> res;
	for (size_t i = 1; i + 1 <= deq.size(); i += 2)
		res.push_back(deq[i]);
	sortdeque(res);
	for (size_t u = 0; u < deq.size(); u += 2)
		res.insert(res.begin() + binarySearchDeque(res, deq[u]), deq[u]);
	deq = res;
}

size_t	binarySearchDeque(std::deque<unsigned int> res, unsigned int nb)
{
	if (res[res.size() - 1] < nb)
		return (res.size());
	if (res[0] > nb)
		return (0);
	size_t	first = 0;
	size_t	last = res.size();
	size_t	mid = (first + (last - first) / 2);
	while (first != mid && mid != last)
	{
		if (nb == res[mid])
			return (mid);
		if (nb < res[mid])
			last = mid;
		else if (nb > res[mid])
			first = mid;
		mid = (first + (last - first) / 2);
	}
	return (mid + 1);
}
// /^\ deque fonction end /^\ //