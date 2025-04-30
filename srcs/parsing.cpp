/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:05:16 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:20:37 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsingLib.hpp"
#include "Config.hpp"

// c++ -Wall -Wextra -Werror -std=c++98

/*void identifyKeyword(const std::string& line) {
        std::string word;
        std::istringstream iss(line);
        iss >> word;

	switch (keywordList[word]) {

		case 1: { // server
			break;
		}
		case 2: { // location
			break;
		}
		case 3: { 

			}
}*/

bool lineToSkip(const std::string& line)
{
	size_t firstPrintableOfTheLine = line.find_first_not_of(" \t\n\r\f\v");

	if (firstPrintableOfTheLine == std::string::npos || line[firstPrintableOfTheLine] == '#')
		return true;
	return false;
}

bool endOfInstruction(const std::string& line)
{
	size_t firstPrintableOfTheLine = line.find_first_not_of(" \t\n\r\f\v");

	if (line[firstPrintableOfTheLine] == '}')
		return true;
	return false;
}

int parsingFile() {

	Config conf;


	const char* fileName = "server.conf";

	std::ifstream file(fileName);

	if (!file) {
		std::cerr << "Error cannot open file" << std::endl;
		return (1);
	}

	std::string line;

	while (std::getline(file, line)) {
		
		if (lineToSkip(line))
			continue;
		else
			std::cout << "line : " << line << std::endl;
	}

	file.close();

	return (0);
}
