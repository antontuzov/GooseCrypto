#include "../../include/crypto/sha256.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ss.str();
}

std::string calculate_merkle_root(const std::vector<Transaction>& transactions) {
    if (transactions.empty()) {
        return sha256("");
    }
    
    std::vector<std::string> hashes;
    for (const auto& tx : transactions) {
        hashes.push_back(tx.hash);
    }
    
    while (hashes.size() > 1) {
        if (hashes.size() % 2 != 0) {
            hashes.push_back(hashes.back());
        }
        
        std::vector<std::string> new_hashes;
        for (size_t i = 0; i < hashes.size(); i += 2) {
            std::string combined = hashes[i] + hashes[i + 1];
            new_hashes.push_back(sha256(combined));
        }
        hashes = new_hashes;
    }
    
    return hashes[0];
}