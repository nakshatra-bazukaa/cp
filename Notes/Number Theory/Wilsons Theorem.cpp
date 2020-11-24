// Theorem:
    
    // If
        // p -> prime number
            // then
                // (p-1)! mod p = 
                    // -1 or (p-1) {Both are same}

// Application:
    
    // Value of { n! mod p }
        // if
            // n >= p 
                // is 0
        // else if
            // n < p
                // Clearly, 
                    // (p-1)! mod p = -1
                // Therefore,
                    // (n! * (n+1)*(n+2)*...*(p-1)) mod p = -1
                // Also, 
                    // (a*b) mod m = ((a mod m) * (b mod m)) mod m
                // So, 
                    // n! mod p = -1 * (n+1)^-1 mod p * (n+2)^-1 mod p * ... * (p-1)^-1 mod p
                    // final ans = ans + p 

    // Final result is easily computed using Fermats theorem which uses modular exponization

// Code:
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
    int fermats(int a, int p){
        // Returns mmi of a and p
        return modExp(a, p-2, p);
    }
    // Computes n! mod p
    // O(p-n)
    int wilsons(int n, int p){
        if(n >= p)
            return 0;
        
        int ans = -1;
        for(int i = n+1; i<p; i++)
            ans = (ans*fermats(i, p))%p;
        return ans + p;
    }