#include "../../include/core/transaction.h"
#include "../../include/crypto/sha256.h"
#include "../../include/crypto/keys.h"
#include <sstream>
#include <ctime>

Transaction::Transaction() : amount(0), fee(0), timestamp(0) {}

Transaction::Transaction(const std::string& sender, const std::string& recipient, 
                         double amount, double fee)
    : sender(sender), recipient(recipient), amount(amount), fee(fee) {
    timestamp = std::time(nullptr);
    hash = calculate_hash();
}

std::string Transaction::calculate_hash() const {
    std::stringstream ss;
    ss << sender << recipient << amount << fee << timestamp;
    return sha256(ss.str());
}

void Transaction::sign(const std::string& private_key) {
    signature = sign_data(private_key, serialize());
}

bool Transaction::verify_signature() const {
    return ::verify_signature(sender, serialize(), signature);
}

std::string Transaction::serialize() const {
    std::stringstream ss;
    ss << sender << "," << recipient << "," << amount << "," << fee << "," << timestamp;
    return ss.str();
}

Transaction Transaction::deserialize(const std::string& data) {
    // Simple deserialization for now
    Transaction tx;
    // Implementation would parse the data string
    (void)data; // Suppress unused parameter warning
    return tx;
}