# GooseCrypto API Documentation

## Overview

The GooseCrypto API provides a RESTful interface for interacting with the blockchain node. It supports both HTTP and WebSocket connections for different types of interactions.

## Base URL

```
http://localhost:8080/api/v1
```

## Endpoints

### Get Block by Height

```
GET /block/{height}
```

Retrieve a specific block by its height in the blockchain.

**Response:**
```json
{
  "index": 123,
  "timestamp": 1640995200,
  "previous_hash": "0000000000000000000...",
  "merkle_root": "a1b2c3d4e5f...",
  "transactions": [...],
  "nonce": 12345,
  "hash": "f5e4d3c2b1a..."
}
```

### Get Transaction by Hash

```
GET /transaction/{hash}
```

Retrieve a specific transaction by its hash.

**Response:**
```json
{
  "hash": "a1b2c3d4e5f...",
  "sender": "GC_1234567890abcdef...",
  "recipient": "GC_0987654321fedcba...",
  "amount": 100.0,
  "fee": 1.0,
  "signature": "signature_data...",
  "timestamp": 1640995200
}
```

### Submit New Transaction

```
POST /transaction
```

Submit a new transaction to the network.

**Request Body:**
```json
{
  "sender": "GC_1234567890abcdef...",
  "recipient": "GC_0987654321fedcba...",
  "amount": 100.0,
  "fee": 1.0,
  "signature": "signature_data...",
  "timestamp": 1640995200
}
```

**Response:**
```json
{
  "hash": "a1b2c3d4e5f...",
  "status": "pending"
}
```

### Get Address Balance

```
GET /balance/{address}
```

Get the current balance of a specific address.

**Response:**
```json
{
  "address": "GC_1234567890abcdef...",
  "balance": 1000.0
}
```

### Get Connected Peers

```
GET /peers
```

Get a list of currently connected peers.

**Response:**
```json
{
  "peers": [
    "192.168.1.100:1337",
    "10.0.0.50:1337"
  ]
}
```

### Connect to New Peer

```
POST /peers
```

Connect to a new peer in the network.

**Request Body:**
```json
{
  "address": "192.168.1.200:1337"
}
```

**Response:**
```json
{
  "success": true
}
```

### Get Node Status

```
GET /status
```

Get the current status of the node.

**Response:**
```json
{
  "height": 12345,
  "peers": 8,
  "difficulty": 4,
  "version": "1.0.0"
}
```

## WebSocket Events

```
WS /events
```

Subscribe to real-time events from the blockchain.

**Events:**
- `new_block`: Emitted when a new block is added to the chain
- `new_transaction`: Emitted when a new transaction is added to the mempool
- `peer_connected`: Emitted when a new peer connects
- `peer_disconnected`: Emitted when a peer disconnects

**Event Format:**
```json
{
  "event": "new_block",
  "data": {
    "height": 12346,
    "hash": "a1b2c3d4e5f...",
    "timestamp": 1640995300
  }
}
```