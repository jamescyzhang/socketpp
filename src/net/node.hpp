#ifndef SOCKETPP_SOCKET_HPP
#define SOCKETPP_SOCKET_HPP

#include <exception>
#include <functional>
#include <memory>
#include <mutex>
#include <cstdarg>
#include <stdexcept>

#include <arpa/inet.h>
#include <cerrno>
#include <netinet/in.h>
#include <netdb.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

namespace net
{
    class node
    {
    public:
        typedef std::function<void(const std::string &)>  log_fn_callback;
        typedef int socket_fd;

        enum settings_flag
        {
            NO_FLAGS = 0x00,
            ENABLE_LOG = 0x01,
            ALL_FLAGS = 0xFF
        };

        explicit node(const log_fn_callback &logger, const settings_flag settings = ALL_FLAGS);

        virtual ~node() = 0;

        inline static int get_socket_count()
        {
            return s_socket_count;
        }

    protected:
        static std::string str_format(const std::string format, ...);

        const log_fn_callback m_logger;

        settings_flag m_settings_flags;

    private:
        volatile static int s_socket_count;
        static std::mutex s_mtx_count;
    };

    class resolve_error : public std::logic_error
    {
    public:
        explicit resolve_error(const std::string &msg) : std::logic_error(msg)
        {
        }
    };
}

#endif //SOCKETPP_SOCKET_HPP
