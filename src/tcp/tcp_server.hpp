#ifndef SOCKETPP_TCP_SERVER_HPP
#define SOCKETPP_TCP_SERVER_HPP

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <net/node.hpp>

namespace tcp
{
    class tcp_server : public net::node
    {
    public:
        explicit tcp_server(const log_fn_callback logger, const std::string &str_port,
                            const settings_flag settings = ALL_FLAGS) throw(net::resolve_error);

        ~tcp_server() override;

        tcp_server(const tcp_server &) = delete;

        tcp_server &operator=(const tcp_server &) = delete;

        bool start_listen(node::socket_fd &client_socket);

        int receive(node::socket_fd &client_socket, char *data_ptr, const size_t size) const;

        bool send(const node::socket_fd client_socket, const char *data_ptr, const size_t size) const;

        bool send(const node::socket_fd client_socket, const std::string &data) const;

        bool send(const node::socket_fd client_socket, const std::vector<char> &data) const;

        bool disconnect(const node::socket_fd client_socket) const;

        node::socket_fd m_listen_socket;
        node::socket_fd m_client_sockets[10];
        std::string m_str_port;
        struct sockaddr_in m_serv_addr;
    };
}

#endif //SOCKETPP_TCP_SERVER_HPP
