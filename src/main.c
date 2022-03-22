#include <stdio.h>
#include <string.h>

// Personal headers.
#include "../include/rsa.h"
#include "../include/ascii.h"

// Discord has a character limit of 2000 characters.
// So does this program.
#define MAXCHAR 2000

int main() {

	// This is a basic demo.

	// Define variables.
	int p;           // Secret number #1.
	int q;           // Secret number #2.
	int n;           // Product of p and q. This is publicized.
	int phiN;        // Result of the Charmichael function (or the Phi function) of n.
	int e;           // Value of e such that 1) 1 < e < phiN; and 2) e is coprime with both n and phi
	int d;           // Value of d such that (k * e) * (mod(phiN)) = d for some value of k.
	int m;           // Message.
	int c;           // Ciphertext message.
	int m_0;         // Decrypted message.

	// Save user input to an array.
	char input[MAXCHAR];
	printf("Enter a string to be used to encrypt with RSA (maximum 2000 characters): ");
	fgets(input,MAXCHAR, stdin);
	printf("\n\nString entered: %s", input);

	// Calculate and save array sum and value of nextmost array sum.
	int s = sum(input);
	int nS= nSum(input);
	printf("\n\nSum of string: %d, next sum: %d", s, nS);

	// Increment both p and q to next highest prime value.
	p = increment_until_prime(s);
	q = increment_until_prime(nS);
	printf("\n\np: %d, q: %d", p, q);

	// Check both numbers are prime.
	primality_check(p, q);
	
	// Calculate and save value of n.
	n = calculate_n(p, q);
	printf("\n\nn: %d", n);

	// Calculate and save value of phiN.
	phiN = calculate_phiN(p, q);
	printf("\n\nphiN: %d", phiN);

	// Calculate and save value of e.
	e = calculate_e(phiN);	
	printf("\n\ne: %d", e);

	// Calculate and save value of d.
	d = calculate_d(e, phiN);
	printf("\n\nd: %d\n\n", d);


	// Example string for testing.
	char * testString = "2001 honda civic gang";

	// Encrypting a string:
	// 1. Create another array the same size as the length of the original message.
	int inputLength = strlen(testString);
	int cryptedInput[inputLength];
	for (int i = 0; i < inputLength; i++) {
		// 2. Iterate over the original message, outputting the ASCII values to
		// the same spot in the new array.
		cryptedInput[i] = testString[i];

		// 3. Iterate over the new array, running the encrypt function over each
		// array value and writing the output over the original ASCII value.

		// Calculate and save value of c.
		c = encrypt(e, cryptedInput[i], n);
		cryptedInput[i] = c;

		// 4. Print out encrypted array.
		printf("%d\t", cryptedInput[i]);
	}
	
	printf("\n\n");

	// Decrypting a string:
	for (int i = 0; i < inputLength; i++) {
		// 1. Iterate over the new array, running the decrypt function over each
		// array value and writing the output over the encrypted ASCII value.
		m_0 = decrypt(cryptedInput[i], d, n);

		// 2. Iterate over the ASCII values, outputting the text values to
		// the same spot in the new array.
		cryptedInput[i] = m_0;

		// 3. Print out decrypted array.
		printf("%c", cryptedInput[i]);
	}
}
