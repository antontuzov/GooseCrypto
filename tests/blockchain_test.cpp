#include "../include/core/blockchain.h"
#include "../include/core/transaction.h"
#include <gtest/gtest.h>

// Test Blockchain class
TEST(BlockchainTest, Constructor) {
    Blockchain blockchain;
    
    // Should have genesis block
    EXPECT_EQ(blockchain.get_chain_length(), 1);
}

TEST(BlockchainTest, AddTransaction) {
    Blockchain blockchain;
    Transaction tx("sender", "recipient", 10.0, 1.0);
    
    size_t initial_pending = blockchain.get_pending_transactions().size();
    blockchain.add_transaction(tx);
    size_t after_pending = blockchain.get_pending_transactions().size();
    
    // Transaction should be added to pending transactions
    EXPECT_EQ(after_pending, initial_pending + 1);
}

TEST(BlockchainTest, CreateBlock) {
    Blockchain blockchain;
    Transaction tx("sender", "recipient", 10.0, 1.0);
    blockchain.add_transaction(tx);
    
    size_t initial_length = blockchain.get_chain_length();
    Block new_block = blockchain.create_block();
    blockchain.add_block(new_block);
    size_t final_length = blockchain.get_chain_length();
    
    // Chain should have grown by one block
    EXPECT_EQ(final_length, initial_length + 1);
}

TEST(BlockchainTest, GetBalance) {
    Blockchain blockchain;
    
    // New address should have zero balance
    double balance = blockchain.get_balance("test_address");
    EXPECT_EQ(balance, 0.0);
}

TEST(BlockchainTest, ChainValidation) {
    Blockchain blockchain;
    
    // Genesis block should make chain valid
    EXPECT_TRUE(blockchain.is_chain_valid());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}