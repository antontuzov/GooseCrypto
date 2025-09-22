#ifndef GOOSECRYPTO_P2P_H
#define GOOSECRYPTO_P2P_H

#include <string>
#include <vector>
#include <memory>

class P2PManager {
private:
    int port;
    std::vector<std::string> peers;
    
public:
    P2PManager(int port);
    
    void start_server();
    void connect_to_peer(const std::string& address);
    void broadcast_block(const std::string& block_data);
    void broadcast_transaction(const std::string& transaction_data);
    std::vector<std::string> get_peers() const;
    void sync_chain();
};

#endif // GOOSECRYPTO_P2P_H