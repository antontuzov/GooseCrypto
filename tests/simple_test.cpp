#include "../include/core/block.h"
#include "../include/core/transaction.h"
#include "../include/core/blockchain.h"
#include "../include/core/wallet.h"
#include "../include/crypto/sha256.h"
#include "../include/crypto/keys.h"
#include "../include/network/api_server.h"
#include <iostream>
#include <cassert>

int main() {
    std::cout << "Running comprehensive simple tests..." << std::endl;
    
    // Test Block creation
    Block block(1, "previous_hash", 4);
    std::cout << "Block created successfully" << std::endl;
    
    // Test Transaction creation
    Transaction tx("sender", "recipient", 10.0, 1.0);
    std::cout << "Transaction created successfully" << std::endl;
    
    // Test SHA256
    std::string hash = sha256("test");
    assert(hash.length() == 64); // SHA256 produces 64 hex characters
    std::cout << "SHA256 hash of 'test': " << hash << std::endl;
    
    // Test KeyPair generation
    KeyPair keys = generate_key_pair();
    assert(!keys.public_key.empty());
    assert(!keys.private_key.empty());
    std::cout << "KeyPair generated" << std::endl;
    
    // Test Wallet creation
    Wallet wallet;
    assert(!wallet.get_public_key().empty());
    assert(!wallet.get_private_key().empty());
    assert(!wallet.get_address().empty());
    assert(wallet.get_address().substr(0, 3) == "GC_");
    std::cout << "Wallet created with address: " << wallet.get_address() << std::endl;
    
    // Test Wallet signing and verification
    std::string data = "test data for signing";
    std::string signature = wallet.sign_data(data);
    assert(!signature.empty());
    bool is_valid = wallet.verify_signature(data, signature);
    assert(is_valid);
    std::cout << "Wallet signing and verification working" << std::endl;
    
    // Test Blockchain creation
    Blockchain blockchain;
    assert(blockchain.get_chain_length() >= 1); // Should have at least genesis block
    std::cout << "Blockchain created with " << blockchain.get_chain_length() << " blocks" << std::endl;
    
    std::cout << "All comprehensive tests passed!" << std::endl;
    return 0;
}