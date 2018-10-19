/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:18:22 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/09 19:43:34 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class	Data
{
	private:
	std::string		_s1;	
	int				_n;
	std::string		_s2;	

	public:
	std::string		getS1();
	std::string		getS2();
	int				getN();

	Data(std::string s1, int n, std::string s2);
	Data(Data const & src);
	~Data();

	Data const &	operator=(Data const & rhs);
};

#endif
