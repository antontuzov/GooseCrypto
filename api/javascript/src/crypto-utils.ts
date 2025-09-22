// crypto-utils.ts
import * as crypto from 'crypto';
import { ec as EC } from 'elliptic';

export class CryptoUtils {
  private static ec = new EC('secp256k1');

  static sha256(data: string): string {
    return crypto.createHash('sha256').update(data).digest('hex');
  }

  static generateKeyPair(): { publicKey: string; privateKey: string } {
    const keyPair = this.ec.genKeyPair();
    return {
      publicKey: keyPair.getPublic('hex'),
      privateKey: keyPair.getPrivate('hex')
    };
  }

  static signData(privateKey: string, data: string): string {
    const key = this.ec.keyFromPrivate(privateKey, 'hex');
    const signature = key.sign(this.sha256(data));
    return signature.toDER('hex');
  }

  static verifySignature(publicKey: string, data: string, signature: string): boolean {
    const key = this.ec.keyFromPublic(publicKey, 'hex');
    return key.verify(this.sha256(data), signature);
  }

  static generateAddress(publicKey: string): string {
    return 'GC_' + this.sha256(publicKey).slice(0, 40); // GC for GooseCrypto
  }
  
  static validateAddress(address: string): boolean {
    return address.length === 43 && address.startsWith('GC_');
  }
}