// Square sum lazy propogation

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
class Node{
    public:
    int sum, sumSq;
};
class Lazy{
    public:
    int type, val;
    Lazy(){
        type = -1;
    }
};
void buildTree(int *arr, Node *tree, int start, int end, int currNode){
    if(start == end){
        tree[currNode].sum = arr[start];
        tree[currNode].sumSq = arr[start]*arr[start];
        return;
    }

    int mid = (start+end)/2;

    buildTree(arr, tree, start, mid, 2*currNode);
    buildTree(arr, tree, mid+1, end, 2*currNode+1);

    tree[currNode].sum = tree[2*currNode].sum + tree[2*currNode+1].sum;
    tree[currNode].sumSq = tree[2*currNode].sumSq + tree[2*currNode+1].sumSq;
}
void updateTree(Node *tree, Lazy *lazy, int start, int end, int left, int right, int currNode, int currVal, int type){
    if(start > end)
		return;

    int nodeCount = end-start+1;

    if(lazy[currNode].type != -1){
        if(lazy[currNode].type == 0){
            tree[currNode].sum = lazy[currNode].val*nodeCount;
            tree[currNode].sumSq = lazy[currNode].val*lazy[currNode].val*nodeCount;
        }
        else{
            tree[currNode].sumSq += lazy[currNode].val*((nodeCount*lazy[currNode].val) + (2*tree[currNode].sum));
            tree[currNode].sum += nodeCount*lazy[currNode].val; 
        }
        lazy[2*currNode].type = lazy[currNode].type;
        lazy[2*currNode].val = lazy[currNode].val;
        lazy[2*currNode+1].type = lazy[currNode].type;
        lazy[2*currNode+1].val = lazy[currNode].val;
        lazy[currNode].val = 0;
        lazy[currNode].type = -1;
    }

    // No overlap
    if(left > end || right < start)
		return;

    // complete overlap
    if(left <= start && end <= right){
        if(type == 0){
            tree[currNode].sum = currVal*nodeCount;
            tree[currNode].sumSq = currVal*currVal*nodeCount;
            if(start != end){
                lazy[2*currNode].val = currVal;
                lazy[2*currNode].type = type;
                lazy[2*currNode+1].val = currVal;
                lazy[2*currNode+1].type = type;
            }
        }
        else{
            tree[currNode].sumSq += currVal*((nodeCount*currVal) + (2*tree[currNode].sum));
            tree[currNode].sum += nodeCount*currVal;
            if(start != end){
                lazy[2*currNode].val += currVal;
                lazy[2*currNode].type = type;
                lazy[2*currNode+1].val += currVal;
                lazy[2*currNode+1].type = type;
            }
        }
		return;
    }

    // Partial overlap
    int mid = (start+end)/2;
    updateTree(tree, lazy, start, mid, left, right, 2*currNode, currVal, type);
    updateTree(tree, lazy, mid+1, end, left, right, 2*currNode+1, currVal, type);

    tree[currNode].sum = tree[2*currNode].sum + tree[2*currNode+1].sum;
    tree[currNode].sumSq = tree[2*currNode].sumSq + tree[2*currNode+1].sumSq;
}
int query(Lazy* lazy, Node *tree, int start, int end, int currNode, int left, int right){
	// Completly outside given range
	if(start>right || end<left)
		return 0;
    
    int nodeCount = end-start+1;

    if(lazy[currNode].type != -1){
        if(lazy[currNode].type == 0){
            tree[currNode].sum = lazy[currNode].val*nodeCount;
            tree[currNode].sumSq = lazy[currNode].val*lazy[currNode].val*nodeCount;
        }
        else{
            tree[currNode].sumSq += lazy[currNode].val*((nodeCount*lazy[currNode].val) + (2*tree[currNode].sum));
            tree[currNode].sum += nodeCount*lazy[currNode].val; 
        }
        lazy[2*currNode].type = lazy[currNode].type;
        lazy[2*currNode].val = lazy[currNode].val;
        lazy[2*currNode+1].type = lazy[currNode].type;
        lazy[2*currNode+1].val = lazy[currNode].val;
        lazy[currNode].val = 0;
        lazy[currNode].type = -1;
    }

	// Completly inside given range 
	if(start>=left && end<=right){
		return tree[currNode].sumSq;
	}
	// Partially inside and partially outside 
	int mid = (start+end)/2;
	int ans1 = query(lazy, tree, start, mid, 2*currNode, left, right);
	int ans2 = query(lazy, tree, mid+1, end, 2*currNode+1, left, right);

	return ans1+ans2;
}
void solve(int t){
    cout<<"Case "<<t<<':'<<endl;
    int n, q;
    cin>>n>>q;
    int *arr = new int[n]();
    f(i, 0, n)
        cin>>arr[i];
    
    Node *tree = new Node[4*n]();
    Lazy *lazy = new Lazy[4*n]();

    buildTree(arr, tree, 0, n-1, 1);

    loop(q){
        int type, st, nd;
        cin>>type>>st>>nd;
        if(type == 2){
            cout<<query(lazy, tree, 0, n-1, 1, st-1, nd-1)<<endl;
        }
        else{
            int x;
            cin>>x;
            updateTree(tree, lazy, 0, n-1, st-1, nd-1, 1, x, type);
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