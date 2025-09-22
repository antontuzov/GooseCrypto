# GooseCrypto Blockchain

 Blockchain implementation in C++ with JavaScript/TypeScript API integration.

## Project Structure

```
goosecrypto/
├── CMakeLists.txt
├── Makefile
├── build.sh
├── run.sh
├── Dockerfile
├── docker-compose.yml
├── src/
│   ├── core/
│   │   ├── block.cpp
│   │   ├── blockchain.cpp
│   │   ├── transaction.cpp
│   │   └── wallet.cpp
│   ├── crypto/
│   │   ├── sha256.cpp
│   │   └── keys.cpp
│   ├── network/
│   │   ├── p2p.cpp
│   │   └── api_server.cpp
│   ├── utils/
│   │   ├── logger.cpp
│   │   └── config.cpp
│   └── main.cpp
├── include/
│   ├── core/
│   │   ├── block.h
│   │   ├── blockchain.h
│   │   ├── transaction.h
│   │   └── wallet.h
│   ├── crypto/
│   │   ├── sha256.h
│   │   └── keys.h
│   ├── network/
│   │   ├── p2p.h
│   │   └── api_server.h
│   └── utils/
│       ├── logger.h
│       └── config.h
├── api/
│   ├── javascript/
│   │   ├── package.json
│   │   ├── src/
│   │   │   ├── index.ts
│   │   │   ├── ton-client.ts
│   │   │   └── types.ts
│   │   └── dist/
│   └── examples/
│       ├── node-example.js
│       └── web-example.html
├── tests/
│   ├── block_test.cpp
│   ├── blockchain_test.cpp
│   ├── wallet_test.cpp
│   └── crypto_test.cpp
├── docs/
│   ├── index.md
│   ├── getting-started.md
│   ├── javascript-client.md
│   └── faq.md
└── examples/
```

## Quick Start

### Building the C++ Node

Using the build script:
```bash
# Make the script executable
chmod +x build.sh

# Build the project
./build.sh
```

Using Make:
```bash
# Build the project
make

# Clean build files
make clean

# Rebuild everything
make rebuild

# Run tests
make test
```

Using CMake (manual):
```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the project
make

# Run the node
./goosecrypto_node
```

### Running the Node

Using the run script:
```bash
# Make the script executable
chmod +x run.sh

# Run the node
./run.sh
```

Using Make:
```bash
# Run the node
make run
```

Direct execution:
```bash
# Run the node directly
./build/goosecrypto_node
```

### Using Docker

```bash
# Build and run a single node
docker-compose up

# Build and run in detached mode
docker-compose up -d

# Stop all nodes
docker-compose down
```

### Using the JavaScript Client

```javascript
import { TONClient } from 'goosecrypto-js-client';

const client = new TONClient('http://localhost:8080');
const status = await client.getStatus();
console.log(status);
```

## Features

- Blockchain core implementation in C++
- Proof-of-Stake consensus mechanism
- P2P networking layer
- HTTP REST API with JSON-RPC support
- WebSocket for real-time updates
- JavaScript/TypeScript client library
- Cryptographic functions using OpenSSL

## Dependencies

### C++ Node
- C++17 compiler
- CMake 3.10+
- OpenSSL
- Boost.Asio
- Crow HTTP framework

### JavaScript Client
- Node.js 12+
- TypeScript 5.0+
- axios
- elliptic
- ws (WebSocket)

## API Endpoints

- `GET /api/v1/block/{height}` - Get block by height
- `GET /api/v1/transaction/{hash}` - Get transaction by hash
- `POST /api/v1/transaction` - Submit new transaction
- `GET /api/v1/balance/{address}` - Get address balance
- `GET /api/v1/peers` - Get connected peers
- `POST /api/v1/peers` - Connect to new peer
- `GET /api/v1/status` - Get node status
- `WS /api/v1/events` - WebSocket for real-time events

## Documentation

For comprehensive documentation, please see:
- [Getting Started Guide](docs/getting-started.md)
- [JavaScript Client Guide](docs/javascript-client.md)
- [API Reference](API_DOCUMENTATION.md)
- [Architecture Overview](ARCHITECTURE.md)
- [FAQ](docs/faq.md)

## GitHub Documentation

For information about contributing, security, and project governance, please see:
- [Contributing Guide](CONTRIBUTING.md)
- [Code of Conduct](CODE_OF_CONDUCT.md)
- [Security Policy](SECURITY.md)
- [License](LICENSE)
- [Changelog](CHANGELOG.md)

## License

MIT
