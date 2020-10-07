#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define loop(n) for(ll i = 0; i < n; ++i)
#define ff(i,j,n,m) for(ll i = 0; i < n; ++i) for(ll j = 0; j < m; ++j)
#define f(i,s,e) for(ll i = s; i < e; ++i)
#define fin(i,s,e) for(ll i = s; i <= e; ++i)
#define r(i,s,e) for(ll i = e; i >= s; i--)
#define pl pair<ll,ll>
#define pcl pair<char,ll>
#define vc vector<char>
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define vl vector<ll>
#define vs vector<string>
#define vpl vector<pl>
#define vpcl vector<pcl>
#define all(v) v.begin(), v.end()
#define rev(v) reverse(all(v))
#define minE(v) *min_element(all(v))
#define maxE(v) *max_element(all(v))
#define mp make_pair
#define uml unordered_map<ll,ll>
#define umsl unordered_map<string,ll>
#define umcl unordered_map<char,ll>
#define oml map<ll,ll>
#define maxpq priority_queue<ll>
#define desc greater<ll>()
#define minpq priority_queue<ll,vl,desc>
#define F first
#define S second
#define endl "\n"
#define mod 1000000007
#define precision(i) cout<<fixed; cout<<setprecision(i);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/(__gcd(a,b)))*b
bool prime[1000001];
void sieve(){
    prime[0] = false; prime[1] = false;
    for(ll i=2; i*i <= 1000000; i++)
        if(prime[i] == true)
            for(ll j = i*i; j <= 1000000; j += i)
                prime[j] = false;
}
bool isPrime(ll n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}
inline bool isCoPrime(ll a, ll b){
    return (__gcd(a, b) == 1) ? (true) : (false);
}
inline bool isPowerOfTwo (ll x){
    return (x && (!(x&(x-1)))) ? (true) : (false);
}
void printDivisors(ll n){ 
    fin(i, 1, sqrt(n))
        if (n%i == 0)  
            (n/i == i) ? (cout<<i<<endl) : (cout<<i<<' '<<n/i<<endl); 
} 
void printPrimeFactors(ll n){
    while(n%2 == 0){
        cout<<2<<endl;
        n /= 2;
    }
    for(ll i = 3; i <= sqrt(n); i += 2)
        while(n%i == 0){
            cout<<i<<endl;
            n /= i;
        }
    if(n > 2)
        cout<<n<<endl;
}
void c_p_p(){
    #ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    #endif
}
void update(ll *tree, ll *lazy, int start, int end, int left, int right, int currNode, ll val){
    if(start > end)
		return;

    int nodeCount = end-start+1;

    if(lazy[currNode] != 0){
        tree[currNode] += lazy[currNode]*nodeCount;
        if(start != end){
        	lazy[2*currNode] += lazy[currNode];
        	lazy[2*currNode+1] += lazy[currNode];    
        }
        lazy[currNode] = 0;
    }

    // No overlap
    if(left > end || right < start)
		return;

    // complete overlap
    if(left <= start && end <= right){
        tree[currNode] += val*nodeCount;
        if(start != end){
            lazy[2*currNode] += val;
            lazy[2*currNode+1] += val;
        }
		return;
    }

    // Partial overlap
    int mid = (start+end)/2;
    update(tree, lazy, start, mid, left, right, 2*currNode, val);
    update(tree, lazy, mid+1, end, left, right, 2*currNode+1, val);

    tree[currNode] = tree[2*currNode] + tree[2*currNode+1];
}
ll query(ll *lazy, ll *tree, int start, int end, int currNode, int left, int right){
	// Completly outside given range
	if(start>right || end<left)
		return 0;

    int nodeCount = end-start+1;

    if(lazy[currNode] != 0){
        tree[currNode] += lazy[currNode]*nodeCount;
        if(start != end){
         	lazy[2*currNode] += lazy[currNode];
        	lazy[2*currNode+1] += lazy[currNode];   
        }
        lazy[currNode] = 0;
    }

	// Completly inside given range 
	if(start>=left && end<=right){
		return tree[currNode];
	}
	// Partially inside and partially outside 
	int mid = (start+end)/2;
	ll ans1 = query(lazy, tree, start, mid, 2*currNode, left, right);
	ll ans2 = query(lazy, tree, mid+1, end, 2*currNode+1, left, right);

	return ans1+ans2;
}
void solve(int t){
    int n, q;
    cin>>n>>q; 
    ll *arr = new ll[n]();
    ll *tree = new ll[4*n]();
    ll *lazy = new ll[4*n]();
    loop(q){
        int type, x, y;
        cin>>type>>x>>y;
        if(type == 0){
            ll v;
            cin>>v;
            update(tree, lazy, 0, n-1, x-1, y-1, 1, v);
        }
        else{
            cout<<query(lazy, tree, 0, n-1, 1, x-1, y-1)<<endl;
        }
    }
}
int main(){
	// c_p_p();
    // memset(prime, true, sizeof(prime));
    // sieve();
    IO
    int t = 1;
    cin>>t;
    fin(i, 1, t) solve(i);
    return 0;
}