/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:48:48 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:19:32 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsingLib.hpp"
#include "Config.hpp"

int main (int argc, char **argv)
{
    if (argc > 2)
    {
        // error too much argument
        return -1;
    }
    if (argc == 2)
    {
        // parsing argv[1]
	parsingFile();
        std::cout << argv[1] << std::endl; //debug
        // execute
        return 0;
    }
    if (argc == 1)
    {
	Config defConf("By default if the conf file is not provided");
	std::cout << defConf;
	// faire avec le fichier de config ou creer une classe avec des valeurs par default ??
        // execute default
        return 0;
    }
    else
    {
        // error argc or bad code
        return -1;
    }
}
