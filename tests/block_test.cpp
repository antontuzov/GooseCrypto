#include "../include/core/block.h"
#include "../include/core/transaction.h"
#include "../include/crypto/sha256.h"
#include <gtest/gtest.h>
#include <string>

// Test Block class
TEST(BlockTest, Constructor) {
    Block block(1, "previous_hash", 4);
    
    EXPECT_EQ(block.index, 1);
    EXPECT_EQ(block.previous_hash, "previous_hash");
    EXPECT_EQ(block.difficulty, 4);
}

TEST(BlockTest, CalculateHash) {
    Block block(1, "previous_hash", 4);
    Transaction tx("sender", "recipient", 10.0, 1.0);
    block.transactions.push_back(tx);
    block.merkle_root = calculate_merkle_root(block.transactions);
    
    std::string hash = block.calculate_hash();
    
    EXPECT_FALSE(hash.empty());
    EXPECT_EQ(hash.length(), 64); // SHA256 produces 64 hex characters
}

TEST(BlockTest, Serialization) {
    Block block(1, "previous_hash", 4);
    std::string serialized = block.serialize();
    
    EXPECT_FALSE(serialized.empty());
}

// Test Transaction class
TEST(TransactionTest, Constructor) {
    Transaction tx("sender", "recipient", 10.0, 1.0);
    
    EXPECT_EQ(tx.sender, "sender");
    EXPECT_EQ(tx.recipient, "recipient");
    EXPECT_EQ(tx.amount, 10.0);
    EXPECT_EQ(tx.fee, 1.0);
}

TEST(TransactionTest, CalculateHash) {
    Transaction tx("sender", "recipient", 10.0, 1.0);
    std::string hash = tx.calculate_hash();
    
    EXPECT_FALSE(hash.empty());
    EXPECT_EQ(hash.length(), 64); // SHA256 produces 64 hex characters
}

TEST(TransactionTest, Serialization) {
    Transaction tx("sender", "recipient", 10.0, 1.0);
    std::string serialized = tx.serialize();
    
    EXPECT_FALSE(serialized.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}