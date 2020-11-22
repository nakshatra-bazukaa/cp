// O(log(n))

    void multiply(int A[2][2], int B[2][2]){
        int fVal = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int sVal = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int tVal = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int lVal = A[1][0] * B[0][1] + A[1][1] * B[1][1];

        A[0][0] = fVal;
        A[0][1] = sVal;
        A[1][0] = tVal;
        A[1][1] = lVal;
    }
    void power(int A[2][2], int n){
        if(n == 0 || n == 1)
            return;

        power(A, n/2);
        multiply(A, A);

        if(n%2 != 0){
            int M[2][2] = {{1, 1}, {1, 0}};
            multiply(A, M);
        }
    }
    int fib(int n){
        if(n == 0 || n == 1)
            return n;
        
        int A[2][2] = {{1, 1}, {1, 0}};
        power(A, n-1);
        return A[0][0];
    }

// Mod

    #define mod 1000000007
    void multiply(unsigned long long A[2][2], unsigned long long B[2][2]){
        unsigned long long fVal = ((A[0][0] * B[0][0])%mod + (A[0][1] * B[1][0])%mod)%mod;
        unsigned long long sVal = ((A[0][0] * B[0][1])%mod + (A[0][1] * B[1][1])%mod)%mod;
        unsigned long long tVal = ((A[1][0] * B[0][0])%mod + (A[1][1] * B[1][0])%mod)%mod;
        unsigned long long lVal = ((A[1][0] * B[0][1])%mod + (A[1][1] * B[1][1])%mod)%mod;

        A[0][0] = fVal;
        A[0][1] = sVal;
        A[1][0] = tVal;
        A[1][1] = lVal;
    }
    void power(unsigned long long A[2][2], unsigned long long n){
        if(n == 0 || n == 1)
            return;

        power(A, n/2);
        multiply(A, A);

        if(n%2 != 0){
            unsigned long long M[2][2] = {{1, 1}, {1, 0}};
            multiply(A, M);
        }
    }
    unsigned long long fib(unsigned long long n){
        if(n == 0 || n == 1)
            return n;
        
        unsigned long long A[2][2] = {{1, 1}, {1, 0}};
        power(A, n-1);
        return A[0][0];
    }