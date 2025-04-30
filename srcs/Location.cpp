/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:17:36 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:19:05 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"

Location::Location() {
        
	path = "";
        root = "";
        indexDefault = "";
}

Location::Location(std::string _path, std::string _root, std::string _indexDefault, bool _getMethod, bool _postMethod, bool _deleteMethod, bool _allowUpload, bool _cgiScript) : path(_path), root(_root), indexDefault(_indexDefault), getMethod(_getMethod), postMethod(_postMethod), deleteMethod(_deleteMethod), allowUpload(_allowUpload), cgiScript(_cgiScript) {
        
	if (cgiScript)
                scripts.insert(std::pair<std::string, std::string>("Python", "./bin/cgi_script"));
}

std::ostream& operator<<(std::ostream& out, const Location& loc) {

	out << "Path : " << loc.path << "\n";
	out << "Root : " << loc.root << "\n";
	out << "Index Default : " << loc.indexDefault << "\n";
	out << "GET Method Allowed : " << (loc.getMethod ? "true" : "false") << "\n";
	out << "POST Method Allowed : " << (loc.postMethod ? "true" : "false") << "\n";
	out << "DELETE Method Allowed : " << (loc.deleteMethod ? "true" : "false") << "\n";
	out << "Allow Upload : " << (loc.allowUpload ? "true" : "false") << "\n";
	out << "CGI Script : " << (loc.cgiScript ? "true" : "false") << "\n";

	for (std::map<std::string, std::string>::const_iterator it = loc.scripts.begin(); it != loc.scripts.end(); ++it) {
		out << "Scripts [language][path of the script] -> ";
		out << "" << it->first << ": " << it->second << "\n";
	}

    return out;
}

Location::~Location() {}
