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
    int index, A, B;
    Node(){
        A = 0;
        B = 0;
        index = 0;
    }
};
void buildTree(int *A, int *B, Node *tree, int start, int end, int currNode){
    if(start == end){
		tree[currNode].A = A[start];
        tree[currNode].B = B[start];
        tree[currNode].index = start;
		return;
	}

	int mid = (start+end)/2;

	buildTree(A, B, tree, start, mid, 2*currNode);
	buildTree(A, B, tree, mid+1, end, 2*currNode+1);

    if(tree[2*currNode].A == tree[2*currNode+1].A){
        if(tree[2*currNode].B < tree[2*currNode+1].B){
            tree[currNode].A = tree[2*currNode].A;
            tree[currNode].B = tree[2*currNode].B;
            tree[currNode].index = tree[2*currNode].index;
        }
        else{
            tree[currNode].A = tree[2*currNode+1].A;
            tree[currNode].B = tree[2*currNode+1].B;
            tree[currNode].index = tree[2*currNode+1].index;
        }
    }
    else if(tree[2*currNode].A > tree[2*currNode+1].A){
        tree[currNode].A = tree[2*currNode].A;
        tree[currNode].B = tree[2*currNode].B;
        tree[currNode].index = tree[2*currNode].index;
    }
    else{
        tree[currNode].A = tree[2*currNode+1].A;
        tree[currNode].B = tree[2*currNode+1].B;
        tree[currNode].index = tree[2*currNode+1].index;
    }
}
Node query(Node *tree, int start, int end, int currNode, int left, int right){
	// Completly outside given range
    Node node;
	if(start>right || end<left)
		return node;

	// Completly inside given range 
	if(start>=left && end<=right){
		return tree[currNode];
	}
	// Partially inside and partially outside 
	int mid = (start+end)/2;
	Node ans1 = query(tree, start, mid, 2*currNode, left, right);
	Node ans2 = query(tree, mid+1, end, 2*currNode+1, left, right);

	if(ans1.A == ans2.A){
        if(ans1.B < ans2.B){
            return ans1;
        }
        else{
            return ans2;
        }
    }
    else if(ans1.A > ans2.A){
        return ans1;
    }
    else{
        return ans2;
    }
}
void solve(int t){
    int n;
    cin>>n; 
    int *A = new int[n]();
    int *B = new int[n]();
    f(i, 0, n) cin>>A[i];
    f(i, 0, n) cin>>B[i];
    Node *tree = new Node[4*n]();
    buildTree(A, B, tree, 0, n-1, 1);
    int q;
    cin>>q;
    loop(q){
        int x, y;
        cin>>x>>y;
        cout<<query(tree, 0, n-1, 1, x-1, y-1).index+1<<endl;
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