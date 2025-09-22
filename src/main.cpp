#include <iostream>
#include "../include/core/blockchain.h"
#include "../include/core/wallet.h"
#include "../include/network/api_server.h"
#include "../include/network/p2p.h"
#include "../include/utils/logger.h"
#include "../include/utils/config.h"

int main(int argc, char* argv[]) {
    // Load configuration
    Config config;
    config.load_from_file("config.json");
    config.load_from_args(argc, argv);
    
    // Setup logger
    std::string log_level_str = config.get_string("node.log_level", "info");
    LogLevel log_level = LogLevel::INFO;
    if (log_level_str == "debug") log_level = LogLevel::DEBUG;
    else if (log_level_str == "warn") log_level = LogLevel::WARN;
    else if (log_level_str == "error") log_level = LogLevel::ERROR;
    
    Logger logger(log_level);
    logger.info("GooseCrypto Blockchain Node starting...");
    
    // Get configuration values
    int p2p_port = config.get_int("node.p2p_port", 1337);
    int api_port = config.get_int("node.api_port", 8080);
    std::string data_dir = config.get_string("node.data_dir", "./data");
    
    logger.info("Configuration loaded:");
    logger.info("  P2P Port: " + std::to_string(p2p_port));
    logger.info("  API Port: " + std::to_string(api_port));
    logger.info("  Data Directory: " + data_dir);
    
    // Create blockchain
    Blockchain blockchain;
    logger.info("Blockchain created with " + std::to_string(blockchain.get_chain_length()) + " blocks");
    
    // Create wallet
    Wallet wallet;
    logger.info("Wallet created with address: " + wallet.get_address());
    
    // Start P2P network
    P2PManager p2p(p2p_port);
    p2p.start_server();
    logger.info("P2P network started on port " + std::to_string(p2p_port));
    
    // Start API server
    APIServer api(api_port);
    api.start();
    logger.info("API server started on port " + std::to_string(api_port));
    
    logger.info("GooseCrypto node is running!");
    
    // In a real implementation, we would have a main loop here
    // For now, we'll just exit
    return 0;
}