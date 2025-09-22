#include "../../include/network/api_server.h"
#include <iostream>

APIServer::APIServer(int port) : port(port) {}

void APIServer::start() {
    std::cout << "Starting API server on port " << port << std::endl;
    // In a real implementation, this would start an HTTP server
    // with all the specified endpoints
    // For now, we'll just print a message
}

void APIServer::stop() {
    std::cout << "Stopping API server" << std::endl;
    // In a real implementation, this would stop the HTTP server
}