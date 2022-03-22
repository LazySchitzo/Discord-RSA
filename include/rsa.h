#ifndef rsa
#define rsa

// Prompt user for two prime numbers.
int prompter(int p, int q);

// Check if p and q are both prime.
void primality_check(int p, int q);

// Increment number to next prime value.
int increment_until_prime(int n);

// Set the product of p and q equal to n.
int calculate_n(int p, int q);

// Find the Carmichael function (or the Phi function) of n.
int calculate_phiN(int p, int q);

// Greatest Common Denominator (Euclid's Algorithm).
// Source: https://stackoverflow.com/a/19738969
int gcd(int a, int b);

// Public Key Value: 
// Choose a number for e that 1) 1 < e < phiN; and 2) e is coprime with both n and phiN.
int calculate_e(int phiN);

// Private Key Value:
// Choose a number such that (e * d) * (mod(phiN)) = d.
int calculate_d(int e, int phiN);

// Take in a message m in the form of a number. Raise m
// to the power of e, then multiply by the mod of n.
int encrypt(int e, int m, int n);

// Take in a message c in the form of a number. Raise c
// to the power of d, then multiply by the mod of n.
int decrypt(int c, int d, int n);

#endif
