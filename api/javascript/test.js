const { TONClient } = require('./dist/index.js');

// Create a client instance
const client = new TONClient('http://localhost:8080');

// Test that the client was created successfully
console.log('TONClient created successfully');

// Test the methods exist
console.log('Available methods:');
console.log('- getBlock:', typeof client.getBlock);
console.log('- getTransaction:', typeof client.getTransaction);
console.log('- sendTransaction:', typeof client.sendTransaction);
console.log('- getBalance:', typeof client.getBalance);
console.log('- getPeers:', typeof client.getPeers);
console.log('- connectToPeer:', typeof client.connectToPeer);
console.log('- getStatus:', typeof client.getStatus);
console.log('- subscribeToEvents:', typeof client.subscribeToEvents);

console.log('Test completed successfully!');