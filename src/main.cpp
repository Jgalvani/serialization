/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:30:37 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/10 16:47:04 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Data.hpp"
#include <stdlib.h>
#include <ctime>
#include <iostream>

void *	concatenate(std::string s1, int n, std::string s2)
{
	size_t len = (sizeof(s1.c_str()) * 2) + sizeof(n);
	char * tab = new char [len];
	void * memory;
	size_t i;

	for ( i = 0; i < s1.size(); i++)
		tab[i] = s1.c_str()[i];

	for (size_t k = 0; k < sizeof(n); k++)
	{
		tab[i] = static_cast<char>(n);
		n = n >> 8;
		i++;
	}

	for (size_t j = 0; j < s2.size(); j++)
		tab[i++] = s2.c_str()[j];

	memory = tab;

	return memory;
}

std::string		randomTab()
{
	std::string alphaNumericalTab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string	auPif = "";

	for (int i = 0; i < 8; i++)
		auPif += alphaNumericalTab[rand() % 62];

	return auPif;
}	

Data * 	deserialize(void * raw)
{
	std::string s1 = "";	
	std::string s2 = "";	
	size_t i;
	int n = 0;

	char *	tab = static_cast<char*>(raw);

	for (i = 0; i < 8; i++)
		s1 += tab[i];	

	i += 4;
	for (size_t j = 0; j < sizeof(int); j++)
	{
		n += static_cast<int>(tab[i]);
		n = n << 8;
		i--;
	}
	
	i += 4;
	for (size_t j = i; j < 20; j++)
		s2 += tab[j];	
	Data *	data = new Data(s1, n, s2);
	delete tab;
	return data;
}

void *	serialize( void )
{
	srand(time(NULL));

	int	n = rand();

	std::string	s1 = randomTab();
	std::string	s2 = randomTab();
	
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	std::cout << "n: " << n << std::endl <<std::endl;

	void *	serialized = concatenate(s1, n, s2); 

	return serialized;
}

int	main()
{
	void * raw = serialize();
	Data * data = deserialize(raw);
	std::cout << "s1: " << data->getS1() << std::endl;
	std::cout << "s2: " << data->getS2() << std::endl;
	std::cout << "n: " << data->getN() << std::endl;
	delete data;
}
