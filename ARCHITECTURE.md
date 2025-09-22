# GooseCrypto Architecture

## Overview

GooseCrypto is a TON-like blockchain implementation with a C++ core and JavaScript/TypeScript API integration. The system is designed with modularity and scalability in mind.

## Core Components

### 1. Blockchain Core (C++)

The core blockchain functionality is implemented in C++ for performance and efficiency.

#### Block
- Represents a single block in the blockchain
- Contains block header information (index, timestamp, previous hash, etc.)
- Contains a collection of transactions
- Implements hash calculation and serialization

#### Transaction
- Represents a value transfer between addresses
- Contains sender, recipient, amount, and fee
- Implements cryptographic signing and verification
- Calculates its own hash for identification

#### Blockchain
- Manages the chain of blocks
- Validates the integrity of the chain
- Manages pending transactions
- Implements consensus mechanisms (Proof-of-Stake)
- Tracks account balances

#### Wallet
- Generates public/private key pairs
- Creates and verifies digital signatures
- Generates addresses from public keys

### 2. Cryptography Layer

Implements cryptographic functions using OpenSSL:

- SHA-256 hashing for block and transaction identification
- ECDSA for digital signatures
- Merkle tree implementation for transaction verification
- Address generation and validation

### 3. Network Layer

#### P2P Network
- Implements peer-to-peer communication using Boost.Asio
- Manages peer discovery and connections
- Propagates blocks and transactions across the network
- Synchronizes chain state between nodes

#### API Server
- Provides HTTP REST API using the Crow framework
- Implements JSON-RPC endpoints
- Supports WebSocket for real-time updates
- Handles client requests and responses

### 4. JavaScript/TypeScript API

Provides a client library for interacting with GooseCrypto nodes:

- TypeScript type definitions for all data structures
- HTTP client for REST API interaction
- WebSocket client for real-time events
- Cryptographic utilities for client-side operations

## Data Flow

1. **Transaction Creation**: Clients create transactions using the JavaScript API
2. **Transaction Signing**: Transactions are signed with private keys
3. **Transaction Submission**: Signed transactions are submitted to a node via HTTP
4. **Transaction Propagation**: Nodes propagate transactions to peers
5. **Block Creation**: Validators collect transactions and create new blocks
6. **Block Validation**: Nodes validate new blocks according to consensus rules
7. **Block Propagation**: Valid blocks are propagated across the network
8. **Chain Update**: Nodes update their local chain with new blocks
9. **Balance Updates**: Account balances are updated based on transactions

## Consensus Mechanism

GooseCrypto implements a Proof-of-Stake (PoS) consensus mechanism:

- Validators are selected based on their stake (balance)
- Validators create new blocks and add them to the chain
- Validators receive transaction fees as rewards
- Chain validity is maintained through cryptographic verification

## Security Features

- Cryptographic hashing for data integrity
- Digital signatures for transaction authentication
- Address validation to prevent invalid transfers
- Peer verification in the P2P network
- Rate limiting and DDoS protection in the API server

## Deployment Options

- **Single Node**: Run a standalone node for development/testing
- **Network**: Deploy multiple nodes in a peer-to-peer network
- **Docker**: Use Docker containers for easy deployment
- **Cloud**: Deploy on cloud platforms using container orchestration