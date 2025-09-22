# JavaScript Client Guide

This guide explains how to use the GooseCrypto JavaScript/TypeScript client to interact with GooseCrypto nodes.

## Installation

```bash
npm install goosecrypto-js-client
```

## Basic Usage

### Importing the Client

```javascript
// ES6 modules
import { TONClient, CryptoUtils } from 'goosecrypto-js-client';

// CommonJS
const { TONClient, CryptoUtils } = require('goosecrypto-js-client');
```

### Creating a Client Instance

```javascript
// Connect to a local node
const client = new TONClient('http://localhost:8080');

// Connect to a remote node
const client = new TONClient('https://node.example.com');
```

## Wallet Management

### Generating a New Wallet

```javascript
// Generate a new key pair
const keyPair = CryptoUtils.generateKeyPair();

// Generate an address from the public key
const address = CryptoUtils.generateAddress(keyPair.publicKey);

console.log('Private Key:', keyPair.privateKey);
console.log('Public Key:', keyPair.publicKey);
console.log('Address:', address);
```

### Signing and Verifying Data

```javascript
const data = "Hello, GooseCrypto!";
const signature = CryptoUtils.signData(keyPair.privateKey, data);

// Verify the signature
const isValid = CryptoUtils.verifySignature(keyPair.publicKey, data, signature);
console.log('Signature valid:', isValid);
```

## Blockchain Interaction

### Getting Node Status

```javascript
try {
  const status = await client.getStatus();
  console.log('Node Status:', status);
  // Output: { height: 123, peers: 5, difficulty: 4, version: "1.0.0" }
} catch (error) {
  console.error('Failed to get status:', error.message);
}
```

### Getting Block Information

```javascript
try {
  // Get block by height
  const block = await client.getBlock(10);
  console.log('Block:', block);
} catch (error) {
  console.error('Failed to get block:', error.message);
}
```

### Getting Transaction Information

```javascript
try {
  // Get transaction by hash
  const transaction = await client.getTransaction('a1b2c3d4e5f...');
  console.log('Transaction:', transaction);
} catch (error) {
  console.error('Failed to get transaction:', error.message);
}
```

### Getting Account Balance

```javascript
try {
  // Get balance for an address
  const balance = await client.getBalance('GC_1234567890abcdef...');
  console.log('Balance:', balance);
} catch (error) {
  console.error('Failed to get balance:', error.message);
}
```

### Sending Transactions

```javascript
try {
  // Create a transaction object
  const transaction = {
    sender: 'GC_sender_address...',
    recipient: 'GC_recipient_address...',
    amount: 100.0,
    fee: 1.0,
    timestamp: Date.now()
  };

  // Sign the transaction
  // Note: In a real implementation, you would sign the transaction with the sender's private key
  
  // Send the transaction
  const txHash = await client.sendTransaction(transaction, senderPrivateKey);
  console.log('Transaction sent with hash:', txHash);
} catch (error) {
  console.error('Failed to send transaction:', error.message);
}
```

## Real-time Events

### Subscribing to Events

```javascript
// Subscribe to real-time events
client.subscribeToEvents((event) => {
  console.log('New event:', event);
  
  switch (event.event) {
    case 'new_block':
      console.log('New block added:', event.data);
      break;
    case 'new_transaction':
      console.log('New transaction:', event.data);
      break;
    case 'peer_connected':
      console.log('New peer connected:', event.data);
      break;
    case 'peer_disconnected':
      console.log('Peer disconnected:', event.data);
      break;
  }
});
```

## Error Handling

All client methods can throw errors. It's important to handle these properly:

```javascript
async function safeGetBalance(address) {
  try {
    const balance = await client.getBalance(address);
    return balance;
  } catch (error) {
    if (error.message.includes('not found')) {
      console.log('Address not found');
      return 0;
    } else if (error.message.includes('network')) {
      console.log('Network error, retrying...');
      // Implement retry logic
    } else {
      console.error('Unexpected error:', error.message);
    }
    return null;
  }
}
```

## Advanced Usage

### Custom HTTP Configuration

```javascript
// You can pass custom axios configuration
const client = new TONClient('http://localhost:8080', {
  timeout: 5000,
  headers: {
    'User-Agent': 'MyApp/1.0'
  }
});
```

### Batch Operations

```javascript
// Get multiple blocks concurrently
async function getMultipleBlocks(heights) {
  const promises = heights.map(height => client.getBlock(height));
  try {
    const blocks = await Promise.all(promises);
    return blocks;
  } catch (error) {
    console.error('Failed to get blocks:', error.message);
    return [];
  }
}
```

## TypeScript Support

The client includes full TypeScript definitions:

```typescript
import { TONClient, Block, Transaction, NodeStatus } from 'goosecrypto-js-client';

const client: TONClient = new TONClient('http://localhost:8080');

async function getStatus(): Promise<NodeStatus> {
  return await client.getStatus();
}
```

## Browser Usage

The client works in browsers as well:

```html
<!DOCTYPE html>
<html>
<head>
  <title>GooseCrypto Browser Example</title>
</head>
<body>
  <script src="https://unpkg.com/goosecrypto-js-client/dist/browser.min.js"></script>
  <script>
    const client = new TONClient('http://localhost:8080');
    
    async function getBalance() {
      try {
        const address = document.getElementById('address').value;
        const balance = await client.getBalance(address);
        document.getElementById('result').innerText = `Balance: ${balance} GC`;
      } catch (error) {
        document.getElementById('result').innerText = `Error: ${error.message}`;
      }
    }
  </script>
  
  <input type="text" id="address" placeholder="Enter address">
  <button onclick="getBalance()">Get Balance</button>
  <div id="result"></div>
</body>
</html>
```

## Best Practices

1. **Always handle errors** - Network requests can fail
2. **Validate addresses** - Use `CryptoUtils.validateAddress()` to verify addresses
3. **Secure private keys** - Never expose private keys in client-side code
4. **Implement retry logic** - Network issues can be temporary
5. **Use HTTPS** - When connecting to remote nodes, use HTTPS for security
6. **Monitor rate limits** - Be respectful of node resources

## API Reference

For detailed information about all available methods and their parameters, see the [API Reference](api-reference.md).