//
// Created by kpilavov on 28.03.23.
//

#include <boost/asio.hpp>
#include <fstream>
#include <iostream>


#define PORT 55555
#define BUFFER_SIZE 256


using boost::asio::ip::tcp;


int main() {
    boost::asio::io_context io_context;

    // Create a TCP client
    tcp::socket socket(io_context);
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), PORT));

    // Open the file to be written
    std::ofstream file("response.txt", std::ios::binary);

    // Receive the chunks of data and write them to the file
    char buffer[BUFFER_SIZE];
    boost::system::error_code error;
    size_t bytes_transferred;
    while (true)
    {
        bytes_transferred = socket.read_some(boost::asio::buffer(buffer), error);
        if (error == boost::asio::error::eof) {
            // End of file reached, break out of the loop
            std::cout << "file received successfully" << std::endl;
            break;
        } else if (error) {
            // An error occurred, handle it
            throw boost::system::system_error(error);
        }
        file.write(buffer, bytes_transferred);
    }

    // Close the file and the socket
    file.close();
    socket.close();

    return 0;
}
