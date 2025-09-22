export declare class CryptoUtils {
    private static ec;
    static sha256(data: string): string;
    static generateKeyPair(): {
        publicKey: string;
        privateKey: string;
    };
    static signData(privateKey: string, data: string): string;
    static verifySignature(publicKey: string, data: string, signature: string): boolean;
    static generateAddress(publicKey: string): string;
    static validateAddress(address: string): boolean;
}
//# sourceMappingURL=crypto-utils.d.ts.map