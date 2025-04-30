/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:46:56 by yohanafi          #+#    #+#             */
/*   Updated: 2025/04/30 18:46:53 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.hpp"

Client::Client(void)
{
    memset(&this->_socket_client, 0, sizeof(this->_socket_client));
    this->_addrLen = sizeof(_socket_client);
}

Client::~Client() {
    // Empty destructor
}
