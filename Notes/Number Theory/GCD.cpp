// 1.)

    // Basic approach

    // O(n)

    int gcd(int a, int b){
        int ans = 0;
        for(int i = 1; i<=min(a,b); i++)
            ans = ((a%i == 0 && b%i == 0) && (i>ans)) ? i : ans;
        return ans;
    }

    int main(){
        int a, b;
        cin>>a>>b;
        cout<<gcd(a, b);
        return 0;
    }

// 2.)

    // Euclid's algo

    // O(log2(n))

    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }