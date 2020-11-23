// Theorem: {For p -> prime number}
    // (a^p) mod p = a
    // a^p ≡ a (mod p)
    // => a^(p-1) ≡ 1 (mpd p) 
    // => (a^(p-1)) mod p = 1

// Application - Calculation of modular inverse
    // => a^-1 * (a^(p-1)) mod p = a^-1
    // => (a^-1 * (a^(p-1)) mod p) mod p = (a^-1) mod p

    // => a^(p-2) mod p = a^-1 mod p

    // We can easily calculate 
        // { a^(p-2) mod p } 
            // by modular exponization

// CODE:
int modExp(int x, int n, int mod){
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    
    long smallAns = modExp(x, n/2, mod);
    long ans = (smallAns * smallAns) % mod;
    if(n%2 != 0)
        ans = (ans * x) % mod;
        
    return int((ans + mod) % mod);
}
int mmi(int a, int p){
    return modExp(a, p-2, p);
}
