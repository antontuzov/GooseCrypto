#include "../../include/core/blockchain.h"
#include "../../include/crypto/sha256.h"
#include <ctime>

Blockchain::Blockchain() : difficulty(4) {
    // Create genesis block
    Block genesis(0, "0", difficulty);
    genesis.merkle_root = calculate_merkle_root(genesis.transactions);
    genesis.hash = genesis.calculate_hash();
    chain.push_back(genesis);
}

void Blockchain::add_block(const Block& block) {
    if (block.previous_hash == get_latest_block_hash()) {
        chain.push_back(block);
        update_balances(block);
    }
}

bool Blockchain::is_chain_valid() const {
    for (size_t i = 1; i < chain.size(); i++) {
        const Block& current_block = chain[i];
        const Block& previous_block = chain[i - 1];
        
        if (current_block.previous_hash != previous_block.hash) {
            return false;
        }
        
        if (current_block.hash != current_block.calculate_hash()) {
            return false;
        }
    }
    return true;
}

double Blockchain::get_balance(const std::string& address) const {
    auto it = balances.find(address);
    if (it != balances.end()) {
        return it->second;
    }
    return 0.0;
}

std::vector<Transaction> Blockchain::get_pending_transactions() const {
    return pending_transactions;
}

void Blockchain::add_transaction(const Transaction& transaction) {
    if (transaction.verify_signature()) {
        pending_transactions.push_back(transaction);
    }
}

Block Blockchain::create_block() {
    Block new_block(chain.size(), get_latest_block_hash(), difficulty);
    new_block.transactions = pending_transactions;
    new_block.mine_block();
    
    pending_transactions.clear();
    return new_block;
}

std::string Blockchain::get_latest_block_hash() const {
    if (chain.empty()) {
        return "0";
    }
    return chain.back().hash;
}

size_t Blockchain::get_chain_length() const {
    return chain.size();
}

std::string Blockchain::select_validator() {
    // Simple PoS implementation - in a real system, this would be more complex
    return "validator_address";
}

void Blockchain::update_balances(const Block& block) {
    for (const auto& tx : block.transactions) {
        balances[tx.sender] -= (tx.amount + tx.fee);
        balances[tx.recipient] += tx.amount;
        
        // Update validator balance with fees
        std::string validator = select_validator();
        balances[validator] += tx.fee;
    }
}