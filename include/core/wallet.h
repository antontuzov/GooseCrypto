#ifndef GOOSECRYPTO_WALLET_H
#define GOOSECRYPTO_WALLET_H

#include <string>
#include "../crypto/keys.h"

class Wallet {
private:
    KeyPair key_pair;
    std::string address;

public:
    Wallet();
    
    const std::string& get_public_key() const;
    const std::string& get_private_key() const;
    const std::string& get_address() const;
    
    void generate_keys();
    std::string sign_data(const std::string& data) const;
    bool verify_signature(const std::string& data, const std::string& signature) const;
};

#endif // GOOSECRYPTO_WALLET_H