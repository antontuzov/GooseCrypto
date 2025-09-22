#ifndef GOOSECRYPTO_KEYS_H
#define GOOSECRYPTO_KEYS_H

#include <string>

struct KeyPair {
    std::string public_key;
    std::string private_key;
};

KeyPair generate_key_pair();
std::string sign_data(const std::string& private_key, const std::string& data);
bool verify_signature(const std::string& public_key, const std::string& data, const std::string& signature);
std::string generate_address(const std::string& public_key);
bool validate_address(const std::string& address);

#endif // GOOSECRYPTO_KEYS_H