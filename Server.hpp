#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string.h>

class Server
{
    private:
    
    public:
        Server();
        Server(const Server &rhs);
        ~Server();
        Server & operator = (const Server &rhs);

        int config(std::string file);
        int defaultconfig();
        int run();
};

#endif