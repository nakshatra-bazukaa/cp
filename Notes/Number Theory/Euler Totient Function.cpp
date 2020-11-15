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

    