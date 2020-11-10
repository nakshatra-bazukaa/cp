// Modulo Inverse
    // A.B = 1 , B is modulo inverse of A

// Multiplicative Modulo Inverse
    // For Multiplicative Modulo Inverse Of A some m will be associated with it
    // (A.B) mod m = 1 , B is multiplicative modulo inverse of A
    // A, m will be given

    // Solution
        => (A.B) mod m = 1
        => (A.B = 1) mod m
        => (A.B - 1) mod m = 0
        => (A.B - 1) = m.q  // {q is an integer}
        => A.B - m.q = 1
        => A.B + m.(-q) = 1
        => A.B + m.Q = 1  // It is a linear diophantine equation
        // Above implies gcd(A, m) = 1
        // So A, m are coprime
        // For B to exist above two conditions must exist

        // Since we have a diophantine eq'n at the end so we can solve in a similar manner

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
        int MMI(int a, int m){
            return extendedEuclid(a, m).x;
        }
