#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define loop(n) for(ll i = 0; i < n; ++i)
#define ff(i,j,n,m) for(ll i = 0; i < n; ++i) for(ll j = 0; j < m; ++j)
#define f(i,s,e) for(ll i = s; i < e; ++i)
#define fin(i,s,e) for(ll i = s; i <= e; ++i)
#define r(i,s,e) for(ll i = e; i >= s; i--)
#define vi vector<int>
#define vl vector<ll>
#define eb emplace_back
#define endl "\n"
void solve(int t){
    ll n;
    // cin>>n;
}
int main(){
    IO
    ll t = 1;
    // cin>>t;
    fin(i, 1, t) solve(i);
    return 0;
}
Tips:-
    vector:
        
        vector<int> a(n);
            for (auto &it : a) cin >> it;

    map:
        
        map<int, int> cnt;
            for (auto [key, value] : cnt)
    
    ------------------------------------

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


void solve(int t){
    ll n;
    // cin>>n;
}
int main(){
    // c_p_p();
    // memset(prime, true, sizeof(prime));
    // sieve();
    IO
    ll t = 1;
    // cin>>t;
    fin(i, 1, t) solve(i);
    return 0;
}

    ------------------------------------

In isPowerOfTwo() function:/* First x in the expression is for the case when x is 0 */
#define inf 1000000000000000
#define infinity 1000000000000000000LL
#define md 998244353
#define umii unordered_map<int,int>
#define umsi unordered_map<string,int>
inline bool isEven(ll num){
    return !(num & 1);
}
inline ll getDigitCount(ll n){
    return floor(log10(n)) + 1;
}
------------------------------------

* CONSTRAINT ANALYSIS :-
  -------------------

    int       -    10^9
    long long -    10^18
   
    -----------------------------------

* COMPLEXITY ANALYSIS :-
  -------------------
 
        N               |                Time Complexity  
    ---------           |                ---------------  
                        |
1.)     10^18           |                O(log(N))
                        |
2.)     10^8            |                O(N)  
                        |
3.)     10^7            |                O(N*log(N))  
                        |
4.)     10^4            |                O(N^2)              
                        |                              
5.)     500             |                O(N^3)                  
                        |                                
6.)     90              |                O(N^4)      
                        |
7.)     20              |                O(2^N)                  
                        |                                
8.)     11              |                O(N!)

Others :-

1.)     2000            |                O(N^2 * log(N))
                        |
2.)     22              |                O(2^N * N)  
                        |
3.)     18              |                O(2^N * N^2)                                

-----------------------------------
Tips:-
    vector:
        
        vector<int> a(n);
            for (auto &it : a) cin >> it;

    map:
        
        map<int, int> cnt;
            for (auto [key, value] : cnt)

-----------------------------------
Stuff :-

    -To initialise the array
        memset()

        memset (str,'-',sizeof(str));

        // ptr ==> Starting address of memory to be filled or name of arr
        // x   ==> Value to be filled
        // n   ==> Number of bytes to be filled starting
        void *memset(void *ptr, int x, size_t n);

    -sort()
       
        sort(arr, arr+n);

        returns sorted array in ascending order.    

    ascii-
        A - 65
        a - 97

    stoi()-

        to convert char array or a string to integer :-

        1.)
        char a[] = "45";
        cout<<stoi(a);  //45

        2.)
        string s = "45";
        cout<<stoi(s);  //45

------------------------------------

1.) IMP. STUFF ABOUT "string" :-

    -To get size of string
    -size()    
    -length()

    -Other string functions :-    
        -substr()
        -find()
        -empty()

        HOW TO?
        string s = "abfdefdef";

        s.size();   //9
        s.length();  //9
        s.substr(3);    //defdef
        s.substr(3,4);  //defd
        s.find("def");  //3
        s.empty()   //false

        getline()?

        string s;
        getline(cin, s);
        //by this our input will not be intrrupted by spaces

    -char* to string
        -{char *str  to  string s},
        -string s(str);

    -char to string
        -string s(1, ch);

    -string to char*
        -char *out = new char[s.size()+1];
        -strcpy(out, s.c_str());

    -reverse a string
        -reverse(str.begin(), str.end());

    ------------------------------------
       

2.) IMP. STUFF ABOUT "vector" :-
   
    -To declare vector
        -Statically
            -vector<int> v;
        -Dynamically
            -vector<int> *v = new vector<int>();

    -To add element
        -v.push_back(10);

    -To access element
        -v[0];
        -v.at(0);

    -To change an element
        -v[0] = 100;

    -To delete last element
        -v.pop_back();

    -To know its size
        -v.size();

    -To know the current capacity of Vector
        -v.capacity();

    -To traverse a vector
        -for (int i = 0; i < v.size(); ++i)
         {
             /* code */
         }

    ------------------------------------

3.) IMP. STUFF ABOUT "unordered_map" :-

    -To declare
        -unordered_map<string, int> ourmap;

    -To insert
        -1.)
            pair<string, int> p("abc", 1);
            ourmap.insert(p);
        -2.)
            ourmap["def"] = 2;

    -To find or access
        -1.)
            ourmap["abc"]
        -2.)
            ourmap.at("abc")

    -To get size
        -ourmap.size()

    -To check Presense
        -ourmap.count("ghi");
            return 0 or 1 (indicating whether present or not)

    -To erase
        -ourmap.erase("ghi"); (erases a whole  key value pair)
        -ourmap.erase(iterator);
        -ourmap.erase(iterator, iterator + x);

    -To find
        -auto i = ourmap.find("abc");

    ------------------------------------

4.) Imp. STUFF ABOUT "pair" :-

    -1.) Operators
        -Say for pair1 and pair2

        -1.) ==
            -It compares the first and second value of those two pairs

        -2.) !=
            -It compares the first values of those two pairs

        -3.) >=, <=
            -returns 0 or 1 by only comparing the first value of the pair

    -2.) Swap
        -Swaps the contents of one pair object with another pair object.
        -The pairs must be of same type.

        -Syntax
            -pair1.swap(pair2);

    ------------------------------------

5.) Imp. STUFF ABOUT "Graphs" :-



    ------------------------------------

6.) Imp. stuff about "Heaps" :-

    i) Underlying DS CBT(Complete Binray Tree)
        - CBT is saved in array:
            -Child  - For parent at i
                        -Left Child = (2*i + 1)
                        -Right Child = (2*i + 2)
            -Parent - Child with i
                        - Parent = (i - 1)/2

------------------------------------

ALGORITHMS :-

1.) Tries
    -Why to use Tries over Hashmap?
        -1.) Space Optimised
        -2.) Fast Searching

    -Variations
        -1.) Compressed Tries
        -2.) Suffix Tries

2.) Primarality test
    - Optimised school method(*)
    -O(root n)

    bool isPrime(int n)
    {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
    }

3.) Backtracking
    1.) Place yourself at starting point
    2.) Explore all the paths possible from that starting point
    3.) insert your element at only correct position and once inserted, move onto smaller problem
    4.) Once you reach base case print your solution
    5.) Once you explore all paths from one point, Backtrack to your previous point  
   
------------------------------------
Misc :-

    int creteNumber(int arr[], int size){
        int t = 1;
        int num = 0;
        for (int i = size - 1; i >= 0; --i)
        {
            num += t*arr[i];
            t *= 10;
        }
        return num;
    }  
   
    ll fastExponentiation(ll n, ll x, ll modulo)
    {
        ll res = 1;
        while(x > 0)
           {
              if(x & 1)
              res = (res*n) % modulo;
              x = x >> 1;
              n = (n * n) % modulo;
           }
           return res;
    }


    ll power(ll n , ll p){
        if(p==0)
           return 1;
     
         ll res = power((n*n)%mod,p/2);
         if(p%2==1)
           res = (n*res)%mod;
     
             return res;
    }

------------------------------------

Tips :-
   
1.  -Reading integer in fastest way

        // Function
        void fastscan(int &number)
        {
            bool negative = false;
            register int c;
            number = 0;          
            c = getchar();
            if (c=='-')
            {
                negative = true;
                c = getchar();
            }
            for (; (c>47 && c<58); c=getchar())
                number = number*10 + c - 48;
            if (negative)
                number *= -1;
        }

        // Description to use
        void fastscan(int &number)
        {
            //variable to indicate sign of input number
            bool negative = false;
            register int c;
         
            number = 0;
         
            // extract current character from buffer
            c = getchar();
            if (c=='-')
            {
                // number is negative
                negative = true;
         
                // extract the next character from the buffer
                c = getchar();
            }
         
            // Keep on extracting characters if they are integers
            // i.e ASCII Value lies from '0'(48) to '9' (57)
            for (; (c>47 && c<58); c=getchar())
                number = number*10 + c - 48;
         
            // if scanned input has a negative sign, negate the
            // value of the input number
            if (negative)
                number *= -1;
        }
         
        // Function Call
        int main()
        {
            int number;
            fastscan(number);
            cout << number << "\n";
            return 0;
        }

2.   Maximum size of the array:
     We must be knowing that the maximum size of array declared inside the main function is of the order of 10^6
     but if you declare array globally then you can declare its size upto 10^7.
 
3.  2D to 1D array:-
    Formula - 1DIndex = rowIndex*LEN_ROW + colIndex

4.  n bits represents 2^n -1 values

5.  While using pow() with integers { (int)(pow(a, b) + 0.5) }

6. pow() --> complexity => O(log(n))
   <<    --> complexity => O(1)

------------------------------------

Bit Manupulation :-



------------------------------------

Number Theory :-

1.) -For any integer m>2  
    { Fn - a term in fibonacci series },
    the sequence (Fn % m) is periodic
    -This period always starts with 01 and is known as Pisano period
                                                       -------------

2.) To compute F(n) % m:{n ~ 10^14}

        F(n) % m = F(n % Pisano(m)) % m;

**  Special sum of fibonacci series

        1.) F0 + F1 + F2 + . . . + Fn = Fn+2 - F1  {F0 = 0, F1 = 1, Fn = Fn-1 + Fn-2}

        2.) F0^2 + F1^2 + F2^2 + . . . + Fn^2 = Fn+1 * Fn