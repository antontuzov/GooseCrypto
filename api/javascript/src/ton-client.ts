// ton-client.ts
import axios from 'axios';
import WebSocket from 'ws';
import { Block, Transaction, NodeStatus } from './types';

export class TONClient {
  private baseUrl: string;
  private wsUrl: string;
  private ws: WebSocket | null = null;

  constructor(baseUrl: string = 'http://localhost:8080') {
    this.baseUrl = baseUrl;
    this.wsUrl = baseUrl.replace('http', 'ws') + '/api/v1/events';
  }

  async getBlock(height: number): Promise<Block> {
    try {
      const response = await axios.get(`${this.baseUrl}/api/v1/block/${height}`);
      return response.data;
    } catch (error: any) {
      throw new Error(`Failed to get block: ${error.message}`);
    }
  }

  async getTransaction(hash: string): Promise<Transaction> {
    try {
      const response = await axios.get(`${this.baseUrl}/api/v1/transaction/${hash}`);
      return response.data;
    } catch (error: any) {
      throw new Error(`Failed to get transaction: ${error.message}`);
    }
  }

  async sendTransaction(transaction: Partial<Transaction>, privateKey: string): Promise<string> {
    try {
      // In a real implementation, we would sign the transaction with the private key
      // and then send it to the network
      const response = await axios.post(`${this.baseUrl}/api/v1/transaction`, transaction);
      return response.data.hash;
    } catch (error: any) {
      throw new Error(`Failed to send transaction: ${error.message}`);
    }
  }

  async getBalance(address: string): Promise<number> {
    try {
      const response = await axios.get(`${this.baseUrl}/api/v1/balance/${address}`);
      return response.data.balance;
    } catch (error: any) {
      throw new Error(`Failed to get balance: ${error.message}`);
    }
  }

  async getPeers(): Promise<string[]> {
    try {
      const response = await axios.get(`${this.baseUrl}/api/v1/peers`);
      return response.data.peers;
    } catch (error: any) {
      throw new Error(`Failed to get peers: ${error.message}`);
    }
  }

  async connectToPeer(address: string): Promise<boolean> {
    try {
      const response = await axios.post(`${this.baseUrl}/api/v1/peers`, { address });
      return response.data.success;
    } catch (error: any) {
      throw new Error(`Failed to connect to peer: ${error.message}`);
    }
  }

  async getStatus(): Promise<NodeStatus> {
    try {
      const response = await axios.get(`${this.baseUrl}/api/v1/status`);
      return response.data;
    } catch (error: any) {
      throw new Error(`Failed to get node status: ${error.message}`);
    }
  }

  subscribeToEvents(callback: (event: any) => void): void {
    try {
      this.ws = new WebSocket(this.wsUrl);
      
      this.ws.on('open', () => {
        console.log('Connected to WebSocket');
      });
      
      this.ws.on('message', (data: WebSocket.Data) => {
        callback(JSON.parse(data.toString()));
      });
      
      this.ws.on('error', (error: Error) => {
        console.error('WebSocket error:', error);
      });
    } catch (error: any) {
      throw new Error(`Failed to subscribe to events: ${error.message}`);
    }
  }
}