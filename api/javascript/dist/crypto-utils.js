"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
exports.CryptoUtils = void 0;
// crypto-utils.ts
const crypto = __importStar(require("crypto"));
const elliptic_1 = require("elliptic");
class CryptoUtils {
    static sha256(data) {
        return crypto.createHash('sha256').update(data).digest('hex');
    }
    static generateKeyPair() {
        const keyPair = this.ec.genKeyPair();
        return {
            publicKey: keyPair.getPublic('hex'),
            privateKey: keyPair.getPrivate('hex')
        };
    }
    static signData(privateKey, data) {
        const key = this.ec.keyFromPrivate(privateKey, 'hex');
        const signature = key.sign(this.sha256(data));
        return signature.toDER('hex');
    }
    static verifySignature(publicKey, data, signature) {
        const key = this.ec.keyFromPublic(publicKey, 'hex');
        return key.verify(this.sha256(data), signature);
    }
    static generateAddress(publicKey) {
        return 'GC_' + this.sha256(publicKey).slice(0, 40); // GC for GooseCrypto
    }
    static validateAddress(address) {
        return address.length === 43 && address.startsWith('GC_');
    }
}
exports.CryptoUtils = CryptoUtils;
CryptoUtils.ec = new elliptic_1.ec('secp256k1');
//# sourceMappingURL=crypto-utils.js.map