const { TONClient, CryptoUtils } = require('../javascript/dist/index.js');

async function main() {
  console.log('GooseCrypto JavaScript Client Example');
  
  // Create wallet
  console.log('\n--- Wallet Creation ---');
  const keyPair = CryptoUtils.generateKeyPair();
  const address = CryptoUtils.generateAddress(keyPair.publicKey);
  
  console.log(`New wallet created:`);
  console.log(`  Address: ${address}`);
  console.log(`  Public Key: ${keyPair.publicKey.substring(0, 32)}...`);
  console.log(`  Private Key: ${keyPair.privateKey.substring(0, 32)}...`);
  
  // Sign and verify data
  console.log('\n--- Cryptographic Operations ---');
  const testData = "Hello, GooseCrypto!";
  const signature = CryptoUtils.signData(keyPair.privateKey, testData);
  const isValid = CryptoUtils.verifySignature(keyPair.publicKey, testData, signature);
  
  console.log(`Data: ${testData}`);
  console.log(`Signature: ${signature.substring(0, 32)}...`);
  console.log(`Signature valid: ${isValid}`);
  
  // Validate address
  const isAddressValid = CryptoUtils.validateAddress(address);
  console.log(`Address valid: ${isAddressValid}`);
  
  // Create client (this would connect to a real node in practice)
  console.log('\n--- Client Operations ---');
  const client = new TONClient('http://localhost:8080');
  
  console.log('Client created successfully');
  console.log('Available methods:');
  console.log('  - getBlock(height)');
  console.log('  - getTransaction(hash)');
  console.log('  - sendTransaction(transaction, privateKey)');
  console.log('  - getBalance(address)');
  console.log('  - getPeers()');
  console.log('  - connectToPeer(address)');
  console.log('  - getStatus()');
  console.log('  - subscribeToEvents(callback)');
  
  // Example of how to use the client (these would fail without a running node)
  console.log('\n--- Example Usage ---');
  console.log('To interact with a real node, you would use:');
  console.log('  const status = await client.getStatus();');
  console.log('  const balance = await client.getBalance(address);');
  console.log('  const block = await client.getBlock(0);');
  
  console.log('\nExample completed successfully!');
}

main().catch(console.error);