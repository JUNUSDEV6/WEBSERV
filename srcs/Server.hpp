/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:55:01 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:10:40 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parsingLib.hpp"
#include "Location.hpp"

class Server {

        private :
                
		std::string serverName;			// name of server ex : localhost
                
		std::string root;			// our main repository
                
		int port;				// port number ex: 8080
                
		int maxBodySize;			// max body size (mo) ex: 10

                std::map<std::string, Location> loc;    // map of routes ex : [/images/][instanciate obj Location]
                
		std::map<int, std::string> error;	// map of http erros ex : [404][/404.html]

        public :

		// default constructor
                Server();

		// constructor custom to set up the default server
                Server(std::string _name, std::string _root, int _port, int _maxBodySize);

		// destructor
                ~Server();

		// overload operator to print all the elements of the obj
                friend std::ostream& operator<<(std::ostream& out, const Server& server);

                //void addLocation // faire une methode qui permet d'add une key et une value dans le container
                //+ add errorpage                // de map Locations et qui instancie en meme temps un nouvel obj Location
};
