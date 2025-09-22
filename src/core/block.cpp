#include "../../include/core/block.h"
#include "../../include/crypto/sha256.h"
#include <sstream>
#include <iomanip>
#include <ctime>

Block::Block() : index(0), timestamp(0), nonce(0), difficulty(0) {}

Block::Block(uint32_t index, const std::string& previous_hash, uint32_t difficulty)
    : index(index), previous_hash(previous_hash), nonce(0), difficulty(difficulty) {
    timestamp = std::time(nullptr);
}

std::string Block::calculate_hash() const {
    std::stringstream ss;
    ss << index << previous_hash << merkle_root << nonce << difficulty << timestamp;
    
    // Add all transactions to the hash
    for (const auto& tx : transactions) {
        ss << tx.hash;
    }
    
    return sha256(ss.str());
}

std::string Block::serialize() const {
    // Simple serialization for now
    std::stringstream ss;
    ss << index << "," << timestamp << "," << previous_hash << "," 
       << merkle_root << "," << nonce << "," << difficulty;
    return ss.str();
}

Block Block::deserialize(const std::string& data) {
    // Simple deserialization for now
    Block block;
    // Implementation would parse the data string
    (void)data; // Suppress unused parameter warning
    return block;
}

void Block::mine_block() {
    // Simple mining implementation
    merkle_root = calculate_merkle_root(transactions);
    hash = calculate_hash();
    
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculate_hash();
    }
}