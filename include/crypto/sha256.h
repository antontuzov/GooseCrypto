#ifndef GOOSECRYPTO_SHA256_H
#define GOOSECRYPTO_SHA256_H

#include <string>
#include <vector>
#include "../core/transaction.h"

std::string sha256(const std::string& input);
std::string calculate_merkle_root(const std::vector<Transaction>& transactions);

#endif // GOOSECRYPTO_SHA256_H