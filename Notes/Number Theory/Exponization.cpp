// Regular exponization:

    // Brute Force:
        // O(n)
            int power(int x, int n){
                if(x == 0)
                    return 0;
                if(n == 0)
                    return 1;

                return x*power(x, n-1);
            }

    // Optimization 1:
        // O(log(n))
            int power(int x, int n){
                if(x == 0)
                    return 0;
                if(n == 0)
                    return 1;

                int val = power(x, n/2);
                if(n%2 == 0)
                    return val*val;
                return val*val*x;
            }

// Modular exponization:(Recursive)
    // O(log(n))

    int modExp(int x, int n, int mod){
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        
        long ans;
        if(n%2 == 0){
            long smallAns = modExp(x, n/2, mod);
            ans = (smallAns * smallAns) % mod;
        }else{
            long smallAns = modExp(x, n-1, mod);
            ans = x % mod;
            ans = (ans * smallAns) % mod;
        }
        return int((ans + mod) % mod);
    }

// Modular exponization:(Iterative)