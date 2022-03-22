#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define variables.
int p;		 Secret number #1.
int q;		 Secret number #2.
int n;		 Product of p and q. This is publicized.
int phiN;	 Result of the Charmichael function (or the Phi function) of n.
int e;		 Value of e such that 1) 1 < e < phiN; and 2) e is coprime with both n and phiN.
int d;		 Value of d such that (k * e) * (mod(phiN)) = d for some value of k.
int m;		 Message.
int c;		 Ciphertext message.
int m_0;	 Decrypted message.
*/

// Prompt user for two prime numbers.
void prompter(int * p, int * q) {

	// Using pointers to pass out two values. 
	// Source: https://stackoverflow.com/a/2620158
	int tmpP, tmpQ;
	printf("Enter a prime number p: ");
	scanf("%d", &tmpP);
	printf("Enter a prime number q: ");
	scanf("%d", &tmpQ);
	*p = tmpP;
	*q = tmpQ;
}

// Check if p and q are both prime.
void primality_check(int p, int q) {

	int t = p / 2;
	for (int i = 2; i <= t; i++) {
		if (p % i == 0) {
			printf("\n\nValue p (%d) is not prime", p);
			exit(0);
		}
	}
	
	t = q / 2;
	for (int i = 2; i <= t; i++) {
		if (q % i == 0) {
			printf("\n\nValue q (%d) is not prime", q);
			exit(0);
		}
	}
	printf("\n\nBoth numbers are prime");
}

// Increment both p and q to next highest prime value.
int increment_until_prime(int n)
{
    int i,j;
    for(i=n+1;;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                break;
        }

        if(j==i)
        {

                n = i;
                break;
        }
    }
    return n;
}

// Set the product of p and q equal to n.
int calculate_n(int p, int q) {
	int n = p * q;
	return n;
}

// Find the Carmichael function (or the Phi function) of n.
int calculate_phiN(int p, int q) {
	int phiN = (p-1) * (q-1);
	return phiN;
}

// Greatest Common Denominator (Euclid's Algorithm).
// Source: https://stackoverflow.com/a/19738969
int gcd(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a % b;

		a = b;
		b = temp;
	}
	return a;
}


// Public Key Value: 
// Choose a number for e that 1) 1 < e < phiN; and 2) e is coprime with both n and phiN.
int calculate_e(int phiN) {
	// Find value of i such that the greatest common denominator of phiN and i is 1.
	int i = 2;
	while (gcd(i, phiN) != 1) {
		i++;
	}

	// When this value is found, set it equal to e.
	int e = i;

	// If e is greater than or equal to phiN, throw an error.
	if (e >= phiN) {
		printf("\n\nERROR: e is greater than or equal to phiN");
		exit(0);
	}

	return e;
}


// Private Key Value:
// Choose a number such that (e * d) * (mod(phiN)) = d.
int calculate_d(int e, int phiN) {
	// Keep multiplying phiN by some multiplier (k) and add 1, then solve for d.
	// If d is not an integer, repeat the process until an integer value is found.
	int k = 1;
	while (((k * phiN) + 1)%e != 0) {
		k++;
	}
	int d = ((k * phiN) + 1)/e;
	return d;
}

// Take in a message m in the form of a number. Raise m
// to the power of e, then multiply by the mod of n.
int encrypt(int e, int m, int n) {
	// (m ^ e) mod(n) = c
	long long x = 1, y = m;
	while (e > 0) {
		if (e % 2 == 1) {
			x = (x * y) % n;
		}
		y = (y * y) % n;
		e /= 2;
	}

	int c = x % n;
	return c;
}

// Take in a message c in the form of a number. Raise c
// to the power of d, then multiply by the mod of n.
int decrypt(int c, int d, int n) {
	// (c ^ d) mod(n) = m
	long long x = 1, y = c;
	while (d > 0) {
		if (d % 2 == 1) {
			x = (x * y) % n;
		}
		y = (y * y) % n;
		d /= 2;
	}

	int m_0 = x % n;
	return m_0;
}

/*
int main() {

	// Testing functions.
	int p, q, n, phiN, e, c, d, m, m_0;
	// Prompt user for two prime numbers.
	prompter(&p, &q);
	printf("p: %d, q: %d", p, q);
	
	// Add comments for this later.
	primality_check(p, q);
	
	// Set the product of p and q equal to n.
	n = calculate_n(p, q);
	printf("\n\nn: %d", n);

	// Find the Carmichael function (or the Phi function) of n.
	phiN = calculate_phiN(p, q);
	printf("\n\nphiN: %d", phiN);
	
	// Public Key Value: 
	// Choose a number for e that 1) 1 < e < phiN; and 2) e is coprime with both n and phiN.
	e = calculate_e(phiN);
	printf("\n\ne: %d", e);

	// Private Key Value:
	// Choose a number such that (e * d) * (mod(phiN)) = d.
	d = calculate_d(e, phiN);
	printf("\n\nd: %d", d);

	// Add comments for this later.
	c = encrypt(e, m, n);
	printf("\n\nc: %d", c);

	// Add comments for this later.
	m_0 = decrypt(c, d, n);
	printf("\n\nm_0: %d", m_0);
}
*/
