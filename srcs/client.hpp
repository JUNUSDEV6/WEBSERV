/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:21:47 by yohanafi          #+#    #+#             */
/*   Updated: 2025/04/30 18:32:40 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT
# define CLIENT
# include <sys/socket.h>
# include <netinet/in.h>   // for sockaddr_in
# include <cstring>

class Client
{
    public:
        socklen_t                 _addrLen;
        struct sockaddr_in   _socket_client;
        int                 _fd_client;
        Client(void);
        ~Client(void);

    private:
        
};

#endif
