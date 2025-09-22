# GooseCrypto Blockchain

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![TypeScript](https://img.shields.io/badge/TypeScript-Ready-blue.svg)](https://www.typescriptlang.org/)

A TON-like blockchain implementation in C++ with JavaScript/TypeScript API integration.

## Features

- 🚀 **High Performance**: Core blockchain implementation in C++17
- 🔐 **Cryptographic Security**: SHA-256 hashing, ECDSA signatures
- 🌐 **P2P Networking**: Peer-to-peer communication layer
- 📡 **RESTful API**: HTTP API with JSON-RPC support
- ⚡ **Real-time Updates**: WebSocket support for live events
- 📦 **JavaScript/TypeScript SDK**: Full-featured client library
- 📋 **Proof-of-Stake**: Energy-efficient consensus mechanism
- 🛠️ **Modular Architecture**: Well-organized, extensible codebase

## Architecture

```
goosecrypto/
├── src/
│   ├── core/          # Core blockchain components
│   ├── crypto/        # Cryptographic functions
│   ├── network/       # P2P and API networking
│   ├── utils/         # Utility functions
│   └── main.cpp       # Entry point
├── include/           # Header files
├── api/               # JavaScript/TypeScript client
├── tests/             # Unit tests
├── docs/              # Documentation
└── examples/          # Usage examples
```

## Getting Started

### Prerequisites

- C++17 compiler (GCC/Clang)
- CMake 3.10+
- OpenSSL development libraries
- Node.js 12+ (for JavaScript API)

### Building the C++ Node

```bash
# Clone the repository
git clone https://github.com/yourusername/goosecrypto.git
cd goosecrypto

# Build using Make
make

# Or build using CMake
mkdir build && cd build
cmake ..
make

# Run the node
./goosecrypto_node
```

### Using the JavaScript Client

```bash
# Install the package
npm install goosecrypto-js-client

# Or use it directly in your project
```

```javascript
import { TONClient, CryptoUtils } from 'goosecrypto-js-client';

// Create client
const client = new TONClient('http://localhost:8080');

// Generate wallet
const keyPair = CryptoUtils.generateKeyPair();
const address = CryptoUtils.generateAddress(keyPair.publicKey);

// Check balance
const balance = await client.getBalance(address);
console.log(`Balance: ${balance} GC`);

// Subscribe to real-time events
client.subscribeToEvents((event) => {
  console.log('New event:', event);
});
```

## API Endpoints

| Endpoint | Method | Description |
|---------|--------|-------------|
| `GET /api/v1/block/{height}` | GET | Get block by height |
| `GET /api/v1/transaction/{hash}` | GET | Get transaction by hash |
| `POST /api/v1/transaction` | POST | Submit new transaction |
| `GET /api/v1/balance/{address}` | GET | Get address balance |
| `GET /api/v1/peers` | GET | Get connected peers |
| `POST /api/v1/peers` | POST | Connect to new peer |
| `GET /api/v1/status` | GET | Get node status |
| `WS /api/v1/events` | WebSocket | Real-time events |

## Docker Deployment

```bash
# Run a single node
docker-compose up

# Run in detached mode
docker-compose up -d

# Scale to multiple nodes
docker-compose up --scale node=3
```

## Development

### Running Tests

```bash
# Run C++ tests
make test

# Run JavaScript tests
cd api/javascript
npm test
```

### Project Structure

- **Core Components**: Block, Transaction, Blockchain, Wallet
- **Consensus**: Proof-of-Stake implementation
- **Networking**: P2P discovery and synchronization
- **API**: RESTful HTTP interface with WebSocket support
- **Security**: Cryptographic hashing and digital signatures

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by TON (The Open Network) architecture
- Uses OpenSSL for cryptographic functions
- Built with modern C++ and TypeScript