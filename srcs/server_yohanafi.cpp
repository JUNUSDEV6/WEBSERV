/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_yohanafi.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:54:07 by yohanafi          #+#    #+#             */
/*   Updated: 2025/05/01 19:07:21 by yohanafi         ###   ########.fr       */
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
#include <sys/epoll.h>
#define MAX_EVENTS 10

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

    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1)
    {
        perror("epoll_create1");
        return ;
    }

    struct epoll_event  ev, events[MAX_EVENTS];
    ev.events = EPOLLIN;
    ev.data.fd = this->server_fd;
    if (epoll_ct1(epoll_fd, EPOLL_CTL_ADD, this->server_fd, &ev) == - 1)
    {
        perror("epoll_ctl: listen_sock");
        return ;
    }
    std::cout << "Server listening on port " << this->port << std::endl;
    
    while (1)
    {
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        for (int i = 0; i < nfds; i++)
        {
            if (events[i].data.fd == this->server_fd)
            {
                // new connexion
                struct sockaddr_in  client_addr;
                socklen_t           client_len = sizeof(client_addr);
                int                 client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
                if (client_fd < 0)
                {
                    std::cout << "accept" << std::endl;
                    continue ;
                }
                std::cout << "New client connected: fd " << client_fd << std::endl;
            }
            else
            {
                //lire la requette
                char    buffer[READ_BUFFER] = {0};
                char    valread = read(events[i].data.fd, buffer, READ_BUFFER);
                if (valread <= 0)
                {
                     close(events[i].data.fd);
                     std::cout << "Client discommected: fd " << events[i].data.fd << std::endl;
                }
                else
                {
                    std::string request(buffer);
                    std::string method = parsMethod(request);
                    std::string path   = parsePath(request);

                    std::cout << "request: " << method << " " << path << std::endl;

                    std::string reponse = buildHttpResonse(path);
                    send(events[i].data.fd, reponse.c_str(), response.size(), 0);
                    close(events[i].data.fd);
                }
            }
            // !!!! pas encore test, implementer les fonction pour parse methode etcs
        }
        //std::cout << "+++++++ Waiting for new connection ++++++++" << std::endl;
        ////poll()
        //if ((client._fd_client = accept(server_fd, (struct sockaddr *)&socket_addr, &client._addrLen)) < 0)
        //{
        //    perror("in accept");
        //    return ;
        //}
        //char buffer[30000] = {0};
        //int valread = read( client._fd_client , buffer, 30000);
        //printf("%s\n",buffer );
        //write(client._fd_client , "hello" , strlen("hello"));
        //printf("------------------Hello message sent-------------------\n");
        //close(client._fd_client);
        ////parse le buffer (et fonction de la methode)
        
        
    }
    
}

ServerYo::~ServerYo() {
    // Empty destructor
}

