#include "../../include/core/wallet.h"
#include "../../include/crypto/keys.h"
#include "../../include/crypto/sha256.h"

Wallet::Wallet() {
    key_pair = generate_key_pair();
    address = generate_address(key_pair.public_key);
}

const std::string& Wallet::get_public_key() const {
    return key_pair.public_key;
}

const std::string& Wallet::get_private_key() const {
    return key_pair.private_key;
}

const std::string& Wallet::get_address() const {
    return address;
}

void Wallet::generate_keys() {
    key_pair = generate_key_pair();
}

std::string Wallet::sign_data(const std::string& data) const {
    return ::sign_data(key_pair.private_key, data);
}

bool Wallet::verify_signature(const std::string& data, const std::string& signature) const {
    return ::verify_signature(key_pair.public_key, data, signature);
}