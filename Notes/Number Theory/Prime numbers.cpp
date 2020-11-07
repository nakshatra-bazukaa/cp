// -prime numbers from 1 to N

// 1.)

    // Basic approach

    // O(n^2)

    bool prime(int n){
        int count = 0;
        for(int i = 1; i<n; i++)
            if(n%i == 0)
                count += (i*i == n) ? 1 : 2;
        return count == 2;
    }
    int check(int n){
        int ans = 0;
        for(int i = 1; i<=n; i++)
            if(prime(i))
                ans++;
        return ans;
    }

// 2.)

    // Optimised Basic approach

    // O(n*sqrt(n))

    bool prime(int n){
        int count = 0;
        for(int i = 1; i<sqrt(n); i++)
            if(n%i == 0)
                count += (i*i == n) ? 1 : 2;
        return count == 2;
    }
    int check(int n){
        int ans = 0;
        for(int i = 1; i<=n; i++)
            if(prime(i))
                ans++;
        return ans;
    }

// 3.)

    // Sieve of eratosthenes

    // O(n)

    bool prime[1000001];
    void sieve(){
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i<1000001; i++){
            if(prime[i])
                for(int j = i*i; j<1000001; j += i)
                    prime[j] = false;
        }
    }
    int check(int n){
        int ans = 0;
        for(int i = 1; i<=n; i++)
            if(prime[i])
                ans++;
        return ans;
    }
    int main(){
        memset(prime, true, sizeof(prime));
        sieve();
        int n; 
        cin>>n;
        cout<<check(n);
        return 0;
    }