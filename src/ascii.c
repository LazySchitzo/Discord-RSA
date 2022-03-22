#include <stdio.h>
#include <string.h>

// Convert and print out a string as ASII values.
void stringToASCII(char * input)
{
	int length = strlen(input);
	for (int i = 0; i < length; i++) {
		printf("%d\n", input[i]);
	}
}

// Calculate sum of array.
int sum(char * input) {
	int mSum = 0;				// Sum of all array values.
	int length = strlen(input);
	for(int j = 0; j < length - 1; j++) {
		mSum += input[j];
	}
	return mSum;
}

// Sum of all array values excluding 1. Not sure what the term for this is.
int nSum(char * input) {
	int nSum = 0;				// Sum of all array values excluding 1.
       						// Not sure what the term for this is.
	int length = strlen(input);
	for(int j = 0; j < length - 2; j++) {
		nSum += input[j];
	}
	return nSum;

}

/*
int main()
{
	// Testing functions.

	// Example string for testing.
	char * input = "2001 honda civic gang";

	stringToASCII(input);

	printf("\n\nSum of array: %d", sum(input));
	
	printf("\n\nSum of array less one value: %d", nSum(input));
	
	return 0;
}
*/
