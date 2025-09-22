# Getting Started with GooseCrypto

This guide will help you get started with GooseCrypto, from installation to running your first node.

## Prerequisites

Before you begin, ensure you have the following installed:

- **C++17 compiler** (GCC 7+ or Clang 5+)
- **CMake** 3.10 or higher
- **OpenSSL** development libraries
- **Git** for version control
- **Node.js** 12+ (for JavaScript API)
- **Docker** (optional, for containerized deployment)

## Installation

### Option 1: Building from Source

```bash
# Clone the repository
git clone https://github.com/yourusername/goosecrypto.git
cd goosecrypto

# Build the project
make

# Or use CMake for more control
mkdir build && cd build
cmake ..
make
```

### Option 2: Using Docker

```bash
# Pull the latest image
docker pull goosecrypto/node:latest

# Run a node
docker run -p 1337:1337 -p 8080:8080 goosecrypto/node
```

## Running Your First Node

After building the project, you can run your first GooseCrypto node:

```bash
# Run the node
./goosecrypto_node

# Or with custom configuration
./goosecrypto_node --config=config.json
```

You should see output similar to:

```
[2025-09-22 15:49:31] [INFO] GooseCrypto Blockchain Node starting...
[2025-09-22 15:49:31] [INFO] Configuration loaded:
[2025-09-22 15:49:31] [INFO]   P2P Port: 1337
[2025-09-22 15:49:31] [INFO]   API Port: 8080
[2025-09-22 15:49:31] [INFO]   Data Directory: ./data
[2025-09-22 15:49:31] [INFO] Blockchain created with 1 blocks
[2025-09-22 15:49:31] [INFO] Wallet created with address: GC_public_key_placeholder
[2025-09-22 15:49:31] [INFO] P2P network started on port 1337
[2025-09-22 15:49:31] [INFO] API server started on port 8080
[2025-09-22 15:49:31] [INFO] GooseCrypto node is running!
```

## Using the JavaScript Client

To use the JavaScript/TypeScript client in your project:

```bash
# Install the package
npm install goosecrypto-js-client
```

```javascript
import { TONClient, CryptoUtils } from 'goosecrypto-js-client';

// Create a client instance
const client = new TONClient('http://localhost:8080');

// Generate a new wallet
const keyPair = CryptoUtils.generateKeyPair();
const address = CryptoUtils.generateAddress(keyPair.publicKey);

console.log(`New wallet address: ${address}`);
```

## Configuration

GooseCrypto can be configured using a JSON configuration file:

```json
{
  "node": {
    "name": "GooseCrypto Node",
    "version": "1.0.0",
    "p2p_port": 1337,
    "api_port": 8080,
    "data_dir": "./data",
    "log_level": "info"
  },
  "blockchain": {
    "difficulty": 4,
    "block_time": 30,
    "min_transaction_fee": 0.001
  },
  "network": {
    "max_peers": 50,
    "discovery_interval": 30,
    "sync_interval": 10
  }
}
```

## Next Steps

1. [Learn about the architecture](architecture.md)
2. [Explore the API](api-reference.md)
3. [Run a network of nodes](running-node.md)
4. [Build your first application](javascript-client.md)

## Troubleshooting

### Common Issues

1. **Missing dependencies**: Ensure all prerequisites are installed
2. **Port conflicts**: Check that ports 1337 and 8080 are available
3. **Permission errors**: Run with appropriate permissions or use Docker

### Getting Help

If you encounter issues:

1. Check the [FAQ](faq.md)
2. Search [existing issues](https://github.com/yourusername/goosecrypto/issues)
3. Create a new issue with detailed information about your problem