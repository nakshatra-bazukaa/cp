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
#define eb emplace_back
#define pb push_back
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
    freopen("output.txt", "w", stdout);
    #endif
}
class Node{
    public:
    int sum, maxsum, bps, bss;
};
void buildTree(int *arr, Node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].sum = arr[start];
        tree[treeNode].maxsum = arr[start];
        tree[treeNode].bps = arr[start];
        tree[treeNode].bss = arr[start];
        return;
    }
    
    int mid = (start + end)/2;

    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
    tree[treeNode].bps = max(tree[2*treeNode].bps, tree[2*treeNode].sum + tree[2*treeNode+1].bps);
    tree[treeNode].bss = max(tree[2*treeNode+1].bss, tree[2*treeNode+1].sum + tree[2*treeNode].bss);

    tree[treeNode].maxsum = max(
        max(
            tree[2*treeNode].maxsum,
            tree[2*treeNode+1].maxsum
        ), 
        max(
            max(
                tree[treeNode].sum,
                tree[treeNode].bps
            ),
            max(
                tree[treeNode].bss,
                tree[2*treeNode].bss+tree[2*treeNode+1].bps
            )
        )
    );
}
Node maxSumSubArr(Node *tree, int start, int end, int treeNode, int left, int right){
    if(start>right || end<left || right<left){
        Node ans;
        ans.sum = INT_MIN;
        ans.maxsum = INT_MIN;
        ans.bps = INT_MIN;
        ans.bss = INT_MIN;
        return ans;
    }
    
    if(start>=left && end<=right)
        return tree[treeNode];
    
    int mid = (start+end)/2;
	Node ans1 = maxSumSubArr(tree, start, mid, 2*treeNode, left, right);
	Node ans2 = maxSumSubArr(tree, mid+1, end, 2*treeNode+1, left, right);

    Node ans;
    if(ans1.sum == INT_MIN){
        ans = ans2;
    }
    else if(ans2.sum == INT_MIN){
        ans = ans1;
    }
    else{
        ans.sum = ans1.sum + ans2.sum;
        ans.bps = max(ans1.bps, ans1.sum + ans2.bps);
        ans.bss = max(ans2.bss, ans2.sum + ans1.bss);
        ans.maxsum = max(
            max(
                ans1.maxsum,
                ans2.maxsum
            ), 
            max(
                max(
                    ans.sum,
                    ans.bps
                ),
                max(
                    ans.bss,
                    ans1.bss+ans2.bps
                )
            )
        );
    }
    
    return ans;
}
void solve(int t){
    ll n;
    cin>>n;
    int *arr = new int[n];
    f(i, 0, n){ 
        cin>>arr[i];
    }
    ll m;
    cin>>m;
    
    Node *tree = new Node[4*n];

    buildTree(arr, tree, 0, n-1, 1);

    loop(m){
        int x, y;
        cin>>x>>y;
        cout<<maxSumSubArr(tree, 0, n-1, 1, x-1, y-1).maxsum<<endl;
    }
}
int main(){
	c_p_p();
    // memset(prime, true, sizeof(prime));
    // sieve();
    IO
    int t = 1;
    // cin>>t;
    fin(i, 1, t) solve(i);
    return 0;
}