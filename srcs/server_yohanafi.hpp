/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_yohanafi.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:54:09 by yohanafi          #+#    #+#             */
/*   Updated: 2025/04/30 18:27:06 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_YO
# define SERVEUR_YO
# include <sys/socket.h>
# include <netinet/in.h>   // for sockaddr_in
# include <iostream>


class   ServerYo
{
    public:
        ServerYo(void);
        ServerYo(const ServerYo &other);
        ServerYo &operator=(const ServerYo &other);
        ~ServerYo(void);

    private:
        struct sockaddr_in socket_addr;
        int               port = 8080;
        //int               adress = 127.0.0.1;
        int               server_fd;

};


#endif