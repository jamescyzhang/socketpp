#ifndef SOCKETPP_TCP_CLIENT_HPP
#define SOCKETPP_TCP_CLIENT_HPP

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include <net/node.hpp>

namespace tcp
{
    class tcp_client : public net::node
    {
    public:
        explicit tcp_client(const log_fn_callback logger,
                            const settings_flag settings = ALL_FLAGS);

        ~tcp_client() override;

        tcp_client(const tcp_client &) = delete;

        tcp_client &operator=(const tcp_client &) = delete;

        bool init_connect(const std::string str_server, const std::string str_port);

        int receive(char *data_ptr, const size_t size) const;

        bool send(const char *data_ptr, const size_t size) const;

        bool send(const std::string &data) const;

        bool send(const std::vector<char> &data) const;

        bool disconnect();

    protected:
        enum connection_status
        {
            CONNECTED,
            DISCONNECTED
        };

        connection_status m_status;
        socket_fd m_socket;
        struct addrinfo *m_p_result_addrinfo;
        struct addrinfo m_hints_addr_info;
    };
}


#endif //SOCKETPP_TCP_CLIENT_HPP
