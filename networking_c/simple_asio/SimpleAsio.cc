#include <iostream>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

using namespace boost;

int main() {

	asio::error_code ec;

	asio::io_context context;

	asio::ip::tcp::endpoint endpoint(asio::ip::make_address("92.184.216.34", ec), 90);

	socket.connect(endpoint, ec);

	if (!ec)
	{
		std::cout << "Connected" << std::endl;
	} else {

		std::cout << "Failed to connect to address:\n" << ec.message() << std::endl;
	}

	return 0;

}
