/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_yohanafi.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:54:07 by yohanafi          #+#    #+#             */
/*   Updated: 2025/04/30 18:46:43 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_yohanafi.hpp"
#include "client.hpp"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

ServerYo::ServerYo(void)
{
   Client client;

    this->server_fd   = socket(AF_INET, SOCK_STREAM, 0);
    
    if (this->server_fd == 0)
    {
        std::cout << "cannot create socket" << std::endl;
        return ;
    }
    
    memset((char *)&socket_addr, 0, sizeof(socket_addr));
    socket_addr.sin_family = AF_INET;
    socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    socket_addr.sin_port = htons(this->port);
    
    if (bind(this->server_fd,(struct sockaddr *)&this->socket_addr, sizeof(this->socket_addr)) < 0)
    {
        std::cout << "bind failed" << std::endl;
        return ;
    }
    
    if (listen(server_fd, 1000) < 0)
    {
        std::cout << "in listen" << std::endl;
        return ;
    }
    
    while (1)
    {
        std::cout << "+++++++ Waiting for new connection ++++++++" << std::endl;
        if ((client._fd_client = accept(server_fd, (struct sockaddr *)&socket_addr, &client._addrLen)) < 0)
        {
            perror("in accept");
            return ;
        }
        
        char buffer[30000] = {0};
        int valread = read( client._fd_client , buffer, 30000);
        printf("%s\n",buffer );
        write(client._fd_client , "hello" , strlen("hello"));
        printf("------------------Hello message sent-------------------\n");
        close(client._fd_client);
        
        
    }
    
}

ServerYo::~ServerYo() {
    // Empty destructor
}

