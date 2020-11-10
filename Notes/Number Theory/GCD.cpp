// 1.)

    // Basic approach

    // O(n)

    int gcd(int a, int b){
        int ans = 0;
        for(int i = 1; i<=min(a,b); i++)
            ans = ((a%i == 0 && b%i == 0) && (i>ans)) ? i : ans;
        return ans;
    }

// 2.)

    // Euclid's algo

    // O(log2(n))

    // here a>b

    int gcd(int a, int b){
        return (b == 0) ? a : gcd(b, a%b);
    }