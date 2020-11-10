// Diophantine equations
    
    // Polynomial eq'n 
        // where Integral solution exist
        // unknowns should be integers

    // let a linear diphantine eq'n be 
        // ax + by = c
        // then it is diophantine eq'n when
            // gcd(a, b) % c == 0

    // Extended euclid's algo will be used to solve these eq's 

    // let eq'n be
        // A.x + B.y = gcd(A, B);

    class Diophantine{
        public:
        int x, y, gcd;
    };
    // This function will return x ans y for the corrosponding A ans B
    Diophantine extendedEuclid(int a, int b){
        Diophantine ans;
        if(b == 0){
            ans.gcd = a;
            ans.x = 1;
            ans.y = 0;
            return ans;
        }
        Diophantine smallAns = extendedEuclid(b, a%b);
        ans.gcd = smallAns.gcd;
        ans.x = smallAns.y;
        ans.y = smallAns.x - (a/b)*smallAns.y;
        return ans;
    }
    