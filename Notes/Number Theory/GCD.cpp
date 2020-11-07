// 1.)

    // Basic approach

    int gcd(int a,int b){
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