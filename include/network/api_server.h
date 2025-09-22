#ifndef GOOSECRYPTO_API_SERVER_H
#define GOOSECRYPTO_API_SERVER_H

#include <string>
#include <memory>

class APIServer {
private:
    int port;
    
public:
    APIServer(int port);
    
    void start();
    void stop();
    
    // HTTP REST API endpoints
    // GET /api/v1/block/{height} - Get block by height
    // GET /api/v1/transaction/{hash} - Get transaction by hash
    // POST /api/v1/transaction - Submit new transaction
    // GET /api/v1/balance/{address} - Get address balance
    // GET /api/v1/peers - Get connected peers
    // POST /api/v1/peers - Connect to new peer
    // GET /api/v1/status - Get node status
    // WS /api/v1/events - WebSocket for real-time events
};

#endif // GOOSECRYPTO_API_SERVER_H