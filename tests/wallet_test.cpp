#include "../include/core/wallet.h"
#include "../include/crypto/keys.h"
#include <gtest/gtest.h>

// Test Wallet class
TEST(WalletTest, Constructor) {
    Wallet wallet;
    
    // Wallet should have a public key, private key, and address
    EXPECT_FALSE(wallet.get_public_key().empty());
    EXPECT_FALSE(wallet.get_private_key().empty());
    EXPECT_FALSE(wallet.get_address().empty());
    
    // Address should start with GC_
    EXPECT_EQ(wallet.get_address().substr(0, 3), "GC_");
}

TEST(WalletTest, KeyGeneration) {
    Wallet wallet;
    std::string original_public_key = wallet.get_public_key();
    std::string original_private_key = wallet.get_private_key();
    
    // Generate new keys
    wallet.generate_keys();
    
    // Keys should be different
    EXPECT_NE(wallet.get_public_key(), original_public_key);
    EXPECT_NE(wallet.get_private_key(), original_private_key);
}

TEST(WalletTest, SigningAndVerification) {
    Wallet wallet;
    std::string data = "test data for signing";
    
    // Sign data
    std::string signature = wallet.sign_data(data);
    EXPECT_FALSE(signature.empty());
    
    // Verify signature
    bool is_valid = wallet.verify_signature(data, signature);
    EXPECT_TRUE(is_valid);
    
    // Verify with wrong data should fail
    bool is_valid_wrong = wallet.verify_signature("wrong data", signature);
    EXPECT_FALSE(is_valid_wrong);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}