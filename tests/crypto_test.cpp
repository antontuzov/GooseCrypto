#include "../include/crypto/sha256.h"
#include "../include/crypto/keys.h"
#include "../include/core/transaction.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

// Test SHA256 functions
TEST(CryptoTest, SHA256Hash) {
    std::string input = "hello world";
    std::string hash = sha256(input);
    
    // Hash should not be empty
    EXPECT_FALSE(hash.empty());
    
    // SHA256 should produce 64 hex characters
    EXPECT_EQ(hash.length(), 64);
    
    // Same input should produce same hash
    std::string hash2 = sha256(input);
    EXPECT_EQ(hash, hash2);
    
    // Different input should produce different hash
    std::string hash3 = sha256("hello world!");
    EXPECT_NE(hash, hash3);
}

// Test Merkle root calculation
TEST(CryptoTest, MerkleRoot) {
    // Empty transactions should produce a hash of empty string
    std::vector<Transaction> empty_transactions;
    std::string empty_root = calculate_merkle_root(empty_transactions);
    EXPECT_EQ(empty_root, sha256(""));
    
    // Single transaction
    Transaction tx1("sender1", "recipient1", 10.0, 1.0);
    std::vector<Transaction> single_transaction = {tx1};
    std::string single_root = calculate_merkle_root(single_transaction);
    EXPECT_EQ(single_root, tx1.hash);
    
    // Multiple transactions
    Transaction tx2("sender2", "recipient2", 20.0, 2.0);
    Transaction tx3("sender3", "recipient3", 30.0, 3.0);
    std::vector<Transaction> multiple_transactions = {tx1, tx2, tx3};
    std::string multiple_root = calculate_merkle_root(multiple_transactions);
    EXPECT_FALSE(multiple_root.empty());
    EXPECT_EQ(multiple_root.length(), 64);
}

// Test key generation
TEST(CryptoTest, KeyGeneration) {
    KeyPair keys = generate_key_pair();
    
    // Keys should not be empty
    EXPECT_FALSE(keys.public_key.empty());
    EXPECT_FALSE(keys.private_key.empty());
    
    // Keys should be different
    EXPECT_NE(keys.public_key, keys.private_key);
}

// Test signing and verification
TEST(CryptoTest, SigningAndVerification) {
    KeyPair keys = generate_key_pair();
    std::string data = "test data for signing";
    
    // Sign data
    std::string signature = sign_data(keys.private_key, data);
    EXPECT_FALSE(signature.empty());
    
    // Verify signature
    bool is_valid = verify_signature(keys.public_key, data, signature);
    EXPECT_TRUE(is_valid);
    
    // Verify with wrong data should fail
    bool is_valid_wrong = verify_signature(keys.public_key, "wrong data", signature);
    EXPECT_FALSE(is_valid_wrong);
    
    // Verify with wrong public key should fail
    KeyPair wrong_keys = generate_key_pair();
    bool is_valid_wrong_key = verify_signature(wrong_keys.public_key, data, signature);
    EXPECT_FALSE(is_valid_wrong_key);
}

// Test address generation
TEST(CryptoTest, AddressGeneration) {
    KeyPair keys = generate_key_pair();
    std::string address = generate_address(keys.public_key);
    
    // Address should not be empty
    EXPECT_FALSE(address.empty());
    
    // Address should start with GC_
    EXPECT_EQ(address.substr(0, 3), "GC_");
    
    // Address should have correct length (GC_ + 40 chars)
    EXPECT_EQ(address.length(), 43);
}

// Test address validation
TEST(CryptoTest, AddressValidation) {
    KeyPair keys = generate_key_pair();
    std::string valid_address = generate_address(keys.public_key);
    std::string invalid_address = "invalid_address";
    
    // Valid address should pass validation
    EXPECT_TRUE(validate_address(valid_address));
    
    // Invalid address should fail validation
    EXPECT_FALSE(validate_address(invalid_address));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}