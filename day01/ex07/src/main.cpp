/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:02:35 by irhett            #+#    #+#             */
/*   Updated: 2018/01/10 22:33:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	find_and_replace(std::string &source, std::string const &find,
		std::string const &replace)
{
	for (std::string::size_type i = 0; 
			(i = source.find(find, i)) != std::string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	ifs(argv[1]);
		std::string		out;
		out = argv[1] + std::string(".replace");
		std::ofstream	ofs(out);

		for (std::string str; std::getline(ifs, str); )
		{
			find_and_replace(str, argv[2], argv[3]);
			ofs << str;
		}
		ifs.close();
		ofs.close();
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " (file) \"search\" \"replace\"";
		std::cout << std::endl;
	}
	return (0);
}
