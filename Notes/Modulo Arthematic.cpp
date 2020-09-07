Range:-

	1.) Positive n

			[0, n-1]

USE:-

	10^9 + 7

	-Handling large numbers
	-Why this?
		1.) Number is very large
		2.) Number is prime

Properties:- 
	1.) (a + b) % c = ((a%c) + (b%c)) % c 
	2.) (a * b) % c = ((a%c) * (b%c)) % c
	3.) (a - b) % c = ((a%c) - (b%c)) % c
	4.) (a / b) % c = ((a%c) / (b%c)) % c
		- b%c exists if, Multiplicative Modulo inverse of b%c exists 
	5.)	If n<0 i.e. n is negative
		then,
		we have to take mod = (a%m + m)%m   