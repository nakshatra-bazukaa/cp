// Representation - Euler Totient function
    // Φ(n) { n>=1 }

// Φ(n) -> Number of 'm' such that 
    // 1 <= m < n and gcd(m, n) = 1 and m is a natural number
        // Basically count of all the number less than n that are coprime to n

// Properties :
    // 1.) Φ(a.b) = Φ(a) * Φ(b)

// Analysis :

    // Approach :

    // Φ(n) = Φ((p1 ^ a1) * (p2 ^ a2) * ... * (pn ^ an)) {HERE : p1, p2, ... are prime numbers}
    // =>  Φ(n) = Φ(p1 ^ a1) * Φ(p2 ^ a2) * ... * Φ(pn ^ an) {By above property}

        // Clearly : {HOW? -> By counting all the numbers not coprime to (p1 ^ a1)}
            // Φ(p1 ^ a1) = p1^a - p1^(a1-1) 
            // => Φ(p1 ^ a1) = p1^a1(1 - 1/p1)

    // By above relation Φ(n) can be easily calculated  

    // So, 

    // Φ(n) = p1^a1(1 - 1/p1) * p2^a2(1 - 1/p2) * ... * pn^an(1 - 1/pn)
    // => Φ(n) = p1^a1 * p2^a2 * ... * pn^an * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn)
    
    // => Φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn)

// Code :

    // O(n*log(log(n)))
    int phi[1000001];
    void phiSieve(){
        for(int i = 1; i<1000001; i++)
            phi[i] = i;
        for(int i = 2; i<1000001; i++)
            if(phi[i] == i){
                phi[i] = i-1;
                for(int j = 2*i; j<1000001; j += i)
                    phi[j] = (phi[j]*(i-1))/i;
            }
    }
    int main(){
        phiSieve();
    }

