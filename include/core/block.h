#ifndef GOOSECRYPTO_BLOCK_H
#define GOOSECRYPTO_BLOCK_H

#include <string>
#include <vector>
#include <cstdint>
#include "transaction.h"

class Block {
public:
    uint32_t index;
    uint64_t timestamp;
    std::string previous_hash;
    std::string merkle_root;
    uint32_t nonce;
    uint32_t difficulty;
    std::vector<Transaction> transactions;
    std::string hash;

    Block();
    Block(uint32_t index, const std::string& previous_hash, uint32_t difficulty);
    
    std::string calculate_hash() const;
    std::string serialize() const;
    static Block deserialize(const std::string& data);
    
    void mine_block();
};

#endif // GOOSECRYPTO_BLOCK_H