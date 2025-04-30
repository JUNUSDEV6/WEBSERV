/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:46:40 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:21:50 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parsingLib.hpp"
#include "Server.hpp"

class Config {
	
	private :

		std::string type;			// from instructions or by default ?
		
		std::map<std::string, Server> servers;	// map of servers ex: [localhost][obj Server]
	
	public :

		// constructor by default
                Config();

		// constructor to set up the server by default
		Config(std::string _default);

		// destructor
                ~Config();

		// overload operator to print all the attributes
		friend std::ostream& operator<<(std::ostream& out, const Config& config);
};
