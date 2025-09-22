#ifndef GOOSECRYPTO_TRANSACTION_H
#define GOOSECRYPTO_TRANSACTION_H

#include <string>
#include <cstdint>

class Transaction {
public:
    std::string sender;
    std::string recipient;
    double amount;
    double fee;
    std::string signature;
    uint64_t timestamp;
    std::string hash;

    Transaction();
    Transaction(const std::string& sender, const std::string& recipient, 
                double amount, double fee);
    
    std::string calculate_hash() const;
    void sign(const std::string& private_key);
    bool verify_signature() const;
    std::string serialize() const;
    static Transaction deserialize(const std::string& data);
};

#endif // GOOSECRYPTO_TRANSACTION_H