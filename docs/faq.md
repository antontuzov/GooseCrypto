# Frequently Asked Questions

## General Questions

### What is GooseCrypto?

GooseCrypto is a TON-like blockchain implementation written in C++ with a JavaScript/TypeScript API. It provides a complete blockchain platform with Proof-of-Stake consensus, P2P networking, and a RESTful API.

### How is GooseCrypto different from TON?

While inspired by TON (The Open Network), GooseCrypto is a separate implementation with its own features and improvements. It focuses on simplicity, performance, and ease of use while maintaining the core concepts of modern blockchain technology.

### What programming languages does GooseCrypto support?

The core blockchain is implemented in C++17 for maximum performance. Additionally, we provide a full-featured JavaScript/TypeScript client library for easy integration with web applications and Node.js services.

## Installation and Setup

### What are the system requirements?

- **C++17 compiler** (GCC 7+ or Clang 5+)
- **CMake** 3.10 or higher
- **OpenSSL** development libraries
- **Git** for version control
- **Node.js** 12+ (for JavaScript API)

### How do I install GooseCrypto?

You can either build from source or use Docker. See the [Getting Started](getting-started.md) guide for detailed instructions.

### I'm getting build errors. What should I do?

Common build issues and their solutions:

1. **Missing dependencies**: Ensure all prerequisites are installed
2. **Compiler not found**: Make sure you have a C++17 compiler installed
3. **Library linking errors**: Check that OpenSSL development libraries are installed
4. **Permission errors**: Run with appropriate permissions or use Docker

## Usage

### How do I run a GooseCrypto node?

After building the project, simply run:

```bash
./goosecrypto_node
```

See the [Running a Node](running-node.md) guide for more details.

### How do I connect to the network?

By default, nodes will listen on port 1337 for P2P connections and port 8080 for API requests. You can configure these in the [configuration file](getting-started.md#configuration).

### How do I create a wallet?

Using the JavaScript client:

```javascript
import { CryptoUtils } from 'goosecrypto-js-client';

const keyPair = CryptoUtils.generateKeyPair();
const address = CryptoUtils.generateAddress(keyPair.publicKey);
```

## Development

### How do I contribute to GooseCrypto?

See our [Contributing Guide](../CONTRIBUTING.md) for detailed information on how to contribute to the project.

### How do I run the tests?

```bash
# Run all tests
./run_tests.sh

# Or run specific test suites
make test-block
make test-blockchain
make test-wallet
make test-crypto
```

### How is the code organized?

See the [Architecture Overview](architecture.md) for details on the code structure.

## Security

### Is GooseCrypto secure?

GooseCrypto implements industry-standard cryptographic functions and follows security best practices. However, as with any software, you should review the code and security practices before using it in production.

### How do I report a security vulnerability?

See our [Security Policy](../SECURITY.md) for information on reporting security vulnerabilities.

## Troubleshooting

### The node won't start. What should I do?

1. Check the logs for error messages
2. Ensure ports 1337 and 8080 are available
3. Verify all dependencies are installed
4. Check the configuration file for errors

### API requests are failing. How can I fix this?

1. Ensure the node is running
2. Check that the API server is listening on the correct port
3. Verify your request format matches the API specification
4. Check the node logs for error messages

### How do I get help?

If you can't find an answer to your question:

1. Check if there's an existing issue on GitHub
2. Create a new issue with detailed information about your problem
3. Join our community chat for real-time help