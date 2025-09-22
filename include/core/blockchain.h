#ifndef GOOSECRYPTO_BLOCKCHAIN_H
#define GOOSECRYPTO_BLOCKCHAIN_H

#include <vector>
#include <string>
#include <map>
#include "block.h"
#include "transaction.h"

class Blockchain {
private:
    std::vector<Block> chain;
    std::vector<Transaction> pending_transactions;
    uint32_t difficulty;
    std::map<std::string, double> balances;

public:
    Blockchain();
    
    void add_block(const Block& block);
    bool is_chain_valid() const;
    double get_balance(const std::string& address) const;
    std::vector<Transaction> get_pending_transactions() const;
    void add_transaction(const Transaction& transaction);
    Block create_block();
    std::string get_latest_block_hash() const;
    size_t get_chain_length() const;
    
    // Proof-of-Stake consensus methods
    std::string select_validator();
    void update_balances(const Block& block);
};

#endif // GOOSECRYPTO_BLOCKCHAIN_H