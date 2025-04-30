/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:56:15 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/04/29 17:11:28 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parsingLib.hpp"

class Location {

        private :

                std::string path;               		// ex : /images/
                
		std::string root;               		// ex : web_repo/images/
                
		std::string indexDefault;       		// file by default ex: index.html
            
		std::map<std::string, std::string> scripts;	// [language][executable]
                
		bool getMethod;					// is GET method allowed ?
                
		bool postMethod;				// is POST method allowed ?
                
		bool deleteMethod;				// is DELETE method allowed ?
                
		bool allowUpload;				// are uploads allowed ?
                
		bool cgiScript;					// is CGI ?


        public :
                
		// default constructor
		Location();
                
		// custom constructor for the default server
		Location(std::string _root, std::string _path, std::string indexDefault, bool getMethod, bool postMethod, bool deleteMethod, bool allowUpload, bool cgiScript);
                
		// destructor
		~Location();
                
		// overload operator to print all the elements of the obj
		friend std::ostream& operator<<(std::ostream& out, const Location& loc);
};
