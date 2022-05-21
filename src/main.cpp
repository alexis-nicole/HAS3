/**********************************************************************************
* @File      main.cpp
* @Author    Alexis Nicole Benini, Ph.D.
* @Date      May 20th, 2022
**********************************************************************************/
#include <iostream>

#include "main.h"

using namespace std;
using namespace boost::asio;
using ip::tcp;

int parse_user_input(int argc, char** argv);

std::string _ip = "127.0.0.1";
std::string _port = "0";

int main(int argc, char** argv)
{

    bool stop = false;
    std::string msg;
    boost::asio::io_service io_service;

    if(parse_user_input(argc,argv) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    //socket creation
    tcp::socket socket(io_service);

    //connection
    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string(_ip),std::stoi(_port)));

    // Wait for the server message

    boost::system::error_code error;
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_at_least(10), error);

    if( error && error != boost::asio::error::eof )
        cout << "Eeceive failed: " << error.message() << endl;
    else 
    {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
    }

    std::cout << "Enter message to send to the server: ";
    std::cin >> msg;

    // Add new line so the server does not complain
    msg += '\n';

    // Sending message to the server
    boost::asio::write( socket, boost::asio::buffer(msg, msg.length()), error );
    if( !error )
        cout << "Message sent" << endl;
    else
        cout << "Send failed: " << error.message() << endl;

    // getting response from server
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_at_least(10), error);

    if( error && error != boost::asio::error::eof )
        cout << "receive failed: " << error.message() << endl;
    else 
    {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
    }

    return EXIT_SUCCESS;
}

int parse_user_input(int argc, char** argv)
{
    try 
    {
        po::options_description desc("Options");
        desc.add_options()
            ("help", "Produces this help message")
            ("v",    "Shows the software version")
            ("ip",   po::value<std::string>(), "Sets the IP of the remote it will connect to")
            ("port", po::value<std::string>(), "Sets the Port of the remote it will connecto to");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        // If the user asks help, just print the help message and then exit.
        if (vm.count("help")) {
            cout << desc << "\n";
            return EXIT_DONE;
        }

        // If the user asks the software version, just print it and then exit.
        if (vm.count("v")) {
            std::cout << "Software version: " << VERSION_MAJOR << "." << VERSION_MINOR << "-" << GIT_HASH << std::endl;
            return EXIT_DONE;
        }

        if (vm.contains("ip"))
        {
            _ip = vm["ip"].as<std::string>();
            std::cout << "IP set to " << _ip << std::endl;
        }
        else
        {
            std::cout << "IP has not been set!" << std::endl;
            return EXIT_FAILURE;
        }

        if (vm.contains("port"))
        {
            _port = vm["port"].as<std::string>();
            std::cout << "Port set to " << _port << std::endl;
        }
        else
        {
            std::cout << "Port has not been set !" << std::endl;
            return EXIT_FAILURE;
        }

    }
    catch (exception& e) 
    {
        cerr << "error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    catch (...) 
    {
        cerr << "Exception of unknown type" << "\n";
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}