"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.TONClient = void 0;
// ton-client.ts
const axios_1 = __importDefault(require("axios"));
const ws_1 = __importDefault(require("ws"));
class TONClient {
    constructor(baseUrl = 'http://localhost:8080') {
        this.ws = null;
        this.baseUrl = baseUrl;
        this.wsUrl = baseUrl.replace('http', 'ws') + '/api/v1/events';
    }
    async getBlock(height) {
        try {
            const response = await axios_1.default.get(`${this.baseUrl}/api/v1/block/${height}`);
            return response.data;
        }
        catch (error) {
            throw new Error(`Failed to get block: ${error.message}`);
        }
    }
    async getTransaction(hash) {
        try {
            const response = await axios_1.default.get(`${this.baseUrl}/api/v1/transaction/${hash}`);
            return response.data;
        }
        catch (error) {
            throw new Error(`Failed to get transaction: ${error.message}`);
        }
    }
    async sendTransaction(transaction, privateKey) {
        try {
            // In a real implementation, we would sign the transaction with the private key
            // and then send it to the network
            const response = await axios_1.default.post(`${this.baseUrl}/api/v1/transaction`, transaction);
            return response.data.hash;
        }
        catch (error) {
            throw new Error(`Failed to send transaction: ${error.message}`);
        }
    }
    async getBalance(address) {
        try {
            const response = await axios_1.default.get(`${this.baseUrl}/api/v1/balance/${address}`);
            return response.data.balance;
        }
        catch (error) {
            throw new Error(`Failed to get balance: ${error.message}`);
        }
    }
    async getPeers() {
        try {
            const response = await axios_1.default.get(`${this.baseUrl}/api/v1/peers`);
            return response.data.peers;
        }
        catch (error) {
            throw new Error(`Failed to get peers: ${error.message}`);
        }
    }
    async connectToPeer(address) {
        try {
            const response = await axios_1.default.post(`${this.baseUrl}/api/v1/peers`, { address });
            return response.data.success;
        }
        catch (error) {
            throw new Error(`Failed to connect to peer: ${error.message}`);
        }
    }
    async getStatus() {
        try {
            const response = await axios_1.default.get(`${this.baseUrl}/api/v1/status`);
            return response.data;
        }
        catch (error) {
            throw new Error(`Failed to get node status: ${error.message}`);
        }
    }
    subscribeToEvents(callback) {
        try {
            this.ws = new ws_1.default(this.wsUrl);
            this.ws.on('open', () => {
                console.log('Connected to WebSocket');
            });
            this.ws.on('message', (data) => {
                callback(JSON.parse(data.toString()));
            });
            this.ws.on('error', (error) => {
                console.error('WebSocket error:', error);
            });
        }
        catch (error) {
            throw new Error(`Failed to subscribe to events: ${error.message}`);
        }
    }
}
exports.TONClient = TONClient;
//# sourceMappingURL=ton-client.js.map