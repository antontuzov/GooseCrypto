import { Block, Transaction, NodeStatus } from './types';
export declare class TONClient {
    private baseUrl;
    private wsUrl;
    private ws;
    constructor(baseUrl?: string);
    getBlock(height: number): Promise<Block>;
    getTransaction(hash: string): Promise<Transaction>;
    sendTransaction(transaction: Partial<Transaction>, privateKey: string): Promise<string>;
    getBalance(address: string): Promise<number>;
    getPeers(): Promise<string[]>;
    connectToPeer(address: string): Promise<boolean>;
    getStatus(): Promise<NodeStatus>;
    subscribeToEvents(callback: (event: any) => void): void;
}
//# sourceMappingURL=ton-client.d.ts.map