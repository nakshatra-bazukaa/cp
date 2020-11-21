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