/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:23:03 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/09 19:43:16 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Data.hpp"

std::string	Data::getS1()
{
	return this->_s1;
}

std::string	Data::getS2()
{
	return this->_s2;
}

int			Data::getN()
{
	return this->_n;
}

Data::Data(std::string s1, int n, std::string s2) : _s1(s1), _n(n), _s2(s2) {}

Data::Data(Data const & src)
{
	*this = src;
}

Data::~Data(){}

Data const &	Data::operator=(Data const & rhs)
{
	if (this != &rhs)
	{
		this->_s1 = rhs._s1;
		this->_s2 = rhs._s2;
		this->_n = rhs._n;
	}
	return *this;
}
