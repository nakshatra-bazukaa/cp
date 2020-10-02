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
    int data, max, smax;
};
void buildTree(int *arr, Node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].data = arr[start];
        tree[treeNode].max = arr[start];
        tree[treeNode].smax = -1;
        return;
    }
    
    int mid = (start + end)/2;

    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode].data = tree[2*treeNode].data + tree[2*treeNode+1].data;

    vi maxarr;
    maxarr.push_back(tree[2*treeNode].max);
    maxarr.push_back(tree[2*treeNode].smax);
    maxarr.push_back(tree[2*treeNode+1].max);
    maxarr.push_back(tree[2*treeNode+1].smax);
    sort(all(maxarr));
    tree[treeNode].max = maxarr[3];
    tree[treeNode].smax = maxarr[2];
}
void updateTree(int *arr, Node *tree, int start, int end, int treeNode, int index, int value){
	if(start == end){
		arr[index] = value;
		tree[treeNode].data = value;
        tree[treeNode].max = value;
        tree[treeNode].smax = -1;
		return;
	}

	int mid = (start+end)/2;
	
	if(index > mid)
		updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
	else
		updateTree(arr, tree, start, mid, 2*treeNode, index, value);
	
	tree[treeNode].data = tree[2*treeNode].data + tree[2*treeNode+1].data;

    vi maxarr;
    maxarr.push_back(tree[2*treeNode].max);
    maxarr.push_back(tree[2*treeNode].smax);
    maxarr.push_back(tree[2*treeNode+1].max);
    maxarr.push_back(tree[2*treeNode+1].smax);
    sort(all(maxarr));
    tree[treeNode].max = maxarr[3];
    tree[treeNode].smax = maxarr[2];
}
pi maxPairSum(Node *tree, int start, int end, int treeNode, int left, int right){
    if(start>right || end<left || right<left)
		return mp(-1, -1);
    
    if(start>=left && end<=right)
        return mp(tree[treeNode].max, tree[treeNode].smax);
    
		

    int mid = (start+end)/2;
	pi ans1 = maxPairSum(tree, start, mid, 2*treeNode, left, right);
	pi ans2 = maxPairSum(tree, mid+1, end, 2*treeNode+1, left, right);

	vi ansarr;
    ansarr.push_back(ans1.first);
    ansarr.push_back(ans1.second);
    ansarr.push_back(ans2.first);
    ansarr.push_back(ans2.second);
    sort(all(ansarr));
    return mp(ansarr[3], ansarr[2]);
}
void solve(int t){
    ll n;
    cin>>n;
    int *arr = new int[n];
    f(i, 0, n){ 
        cin>>arr[i];
    }
    ll q;
    cin>>q;
    
    Node *tree = new Node[4*n];
    f(i, 0, 4*n){
        tree[i].data = 0;
        tree[i].max = INT_MIN;
        tree[i].smax = INT_MIN;
    }

    buildTree(arr, tree, 0, n-1, 1);

    // f(i, 0, 4*n){
        // cout<<tree[i].data<<' '<<tree[i].max<<' '<<tree[i].smax<<"    ";
    // }
    // cout<<endl;

    loop(q){
        char Q;
        cin>>Q;
        int x, y;
        cin>>x>>y;
        if(Q == 'Q'){
            pi ans = maxPairSum(tree, 0, n-1, 1, x-1, y-1);
            if(ans.second == -1)
                cout<<ans.first<<endl;
            else
                cout<<(ans.first)+(ans.second)<<endl;
        }
        else{
            updateTree(arr, tree, 0, n-1, 1, x-1, y);
        }
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