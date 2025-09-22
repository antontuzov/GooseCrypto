export interface Block {
    index: number;
    timestamp: number;
    previous_hash: string;
    merkle_root: string;
    transactions: Transaction[];
    nonce: number;
    hash: string;
}
export interface Transaction {
    hash: string;
    sender: string;
    recipient: string;
    amount: number;
    fee: number;
    signature: string;
    timestamp: number;
}
export interface Wallet {
    address: string;
    publicKey: string;
    privateKey: string;
}
export interface NodeStatus {
    height: number;
    peers: number;
    difficulty: number;
    version: string;
}
//# sourceMappingURL=types.d.ts.map