/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:50:14 by aabel             #+#    #+#             */
/*   Updated: 2024/02/12 15:56:58 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	sortmycontainers(int argc, char **argv)
{
	std::vector<unsigned int> vec;
	std::deque<unsigned int> deq;
    int i = 0;

	while (argv[++i])
	{
		vec.push_back(atoi(argv[i]));
		deq.push_back(atoi(argv[i]));
	}
	clock_t start = clock();
	sortvec(vec);
    clock_t end = clock();
    std::cout << "After for vector : ";
	printvec(vec);
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : ";
	std::cout << std::fixed << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us"<< std::endl;
    start = clock();
	sortdeque(deq);
	end = clock();
    std::cout << "After for deque : ";
    printdeq(deq);
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque : ";
	std::cout << std::fixed << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: wrong number of arguments." << std::endl;
        return (1);
    }
    try
    {
        checknumbers(argv);
        printargv(argv);
        sortmycontainers(argc, argv);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
};