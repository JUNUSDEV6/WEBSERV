/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:15:30 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:24:52 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server() {
        
	root = "";
        serverName = "";
        port = 0;
        maxBodySize = 0;
}

Server::Server(std::string _name, std::string _root, int _port, int _maxBodySize) : serverName(_name), root(_root), port(_port), maxBodySize(_maxBodySize) {
        
	loc.insert(std::pair<std::string, Location>("Images", Location("/images/", "web_repo/images/", "web_repo/images/index.html", false, false, false, false, false)));
        loc.insert(std::pair<std::string, Location>("API", Location("/api/", "web_repo/api/", "web_repo/api/index.html", true, true, true, false, true)));
        loc.insert(std::pair<std::string, Location>("Upload", Location("/upload/", "web_repo/upload/", "web_repo/upload/index.html", true, true, true, true, false)));
        
	error.insert(std::pair<int, std::string>(400, "web_repo/errors/400.html"));
        error.insert(std::pair<int, std::string>(403, "web_repo/errors/403.html"));
        error.insert(std::pair<int, std::string>(404, "web_repo/errors/404.html"));
        error.insert(std::pair<int, std::string>(405, "web_repo/errors/405.html"));
        error.insert(std::pair<int, std::string>(500, "web_repo/errors/500.html"));
        error.insert(std::pair<int, std::string>(502, "web_repo/errors/502.html"));

}

std::ostream& operator<<(std::ostream& out, const Server& server) {
	
	out << "Server Name : " << server.serverName << "\n";
	out << "Root : " << server.root << "\n";
	out << "Port : " << server.port << "\n";
	out << "Max Body Size (Mo) : " << server.maxBodySize << "\n";
	
	out << "\n------------- ... WITH LOCATIONS... -----------\n";
	
	for (std::map<std::string, Location>::const_iterator it = server.loc.begin(); it != server.loc.end(); ++it) {
		out << "\nLocation -> " << it->first << "\n";
		out << it->second;
	}
	
	out << "\n ----------- ... AND ERROR PAGES -------- \n";
	
	for (std::map<int, std::string>::const_iterator it = server.error.begin(); it != server.error.end(); ++it) {
		out << "Error [num of error][path of the file to handle it] -> " << it->first << "|" << it->second << "\n";
	}

    return out;
}

Server::~Server() {}

