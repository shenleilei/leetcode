#include<iostream>
#include<string>
#include"io_service.hpp"
#include"ip/udp.hpp"

bool is_udp_port_available(const std::string & ip, const uint16_t & udp_port)
{
    boost::asio::io_service io;
    boost::asio::ip::udp::socket socket(io);
    socket.open(boost::asio::ip::udp::v4());
    bool is_avaiable = true;
    try
    {
        boost::asio::ip::udp::endpoint local_endpoint =
            boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ip), udp_port);
        socket.bind(local_endpoint);

    }
    catch (const boost::system::system_error & e)
    {
        is_avaiable = false;

    }
    catch (...)
    {
        is_avaiable = false;

    }
    socket.close();
    return is_avaiable;

}

int main()
{
    cout << is_udp_port_available("127.0.0.1", 1080) << endl;
}
