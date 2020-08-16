INFO:-
	
	1.) bitwise operator suitable for turning on a particular bit in a number - |
	2.) bitwise operator suitable for turning off a particular bit in a number - &

Applications:-
	
	1.)Data Compression	

Shift Operators:-
	
	1.) Left shift << 
		Effect : x << n = x*2^n

	2.) Right Shift >>
		Effect : x >> n = floor(x/2^n)

Other Operators:-

	1.) AND (&)
		
		Effect : Similar to logical AND
		
		Remember:
			1.) x & 1 = x
			2.) x & 0 = 0
			3.) x & x = x

	2.) OR (|)
		
		Effect : Similar to logical OR
		
		Remember:
			1.) x | 1 = 1
			2.) x | 0 = x

	3.) NOT (~)
		
		Just flips the bit
		~1 = 0
		~0 = 1

	4.) XOR (^)
		
		TT
		1   1   =   0
		1   0   =   1
		0   1   =   1
		0   0   =   0

			Properties:
				1.) x^1 = ~x

				2.) Identity element
					x^0 = x

				3.) x^x = 0

				4.) ordering of XOR dosnt matter
					(A^B)^C = A^(B^C) = A^C^B

Functions:-

bool checkIthBitIsSet(int n, int i){
	return ((n & 1<<i) == 0) ? false : true;
}
int turnOnIthBit(int n, int i){
	return n|1<<i;
}
int turnOffIthBit(int n, int i){
	return n & (~(1<<i));
}
int flipIthBit(int n, int i){
	return n ^ (1<<i);
}
int returnIdxOfFirstSetBit(int n){
    return log2(n & -n) + 1;
}
int turnOffFirstSetBit(int n, int i){
	return n & (n-1);
}
bool isEven(int n){
	return ((n & 1) == 0) ? true : false;
}
bool isPowerOfTwo (ll x){ 
    bool ans = x && (!(x&(x-1))); /* First x in the expression is for the case when x is 0 */
    return ans;  
}
int removeAllSetBitsFromLSBToI(int n, int i){
	int mask = 1<<(i+1);
	mask--;
	mask = ~mask;
	return n & mask;
}
int removeAllSetBitsFromMSBToI(int n, int i){
	int mask = 1<<i;
	mask--;
	return n & mask;
}

O(log(n))
int countSetBits2(int n){
    int c = 0;
    while(n>0){
        c++;
        n = n & (n-1);
    }
    return c;
}

1.)  Counting Number Of Set Bits

        ex: 
            N = 12(1100) : output = 2
            N = 11(1101) : output = 3

        Approach 1:
        int countSetBits1(int n){
            int c = 0;
            while(n){
                if(n&1 == 1) c++;
                n = n>>1;
            }
            return c;
        }

        O(logN)

        Approach 2: (BETTER ONE)
        Imp. explanation 
        // link(https://www.youtube.com/watch?v=_o7QBzM33J0&list=PL2q4fbVm1Ik7ip1VkWwe5U_CEb93vw6Iu&index=4) 7:30 min
        int countSetBits2(int n){
            int c = 0;
            while(n>0){
                c++;
                n = n & (n-1);
            }
            return c;
        }

        O(no. of set bits) Average case 
        O(logN) Worst case 

https://docs.google.com/spreadsheets/d/1oQeXJQDRX8F98cjCvB-N0r7cjreZu2RsLNNJbQDzPAY/edit#gid=1160016643