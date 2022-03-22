# Discord-RSA-Keys
Finally, a way to generate RSA keys from Discord messages.

## What is this?
This is a program to encrypt and decrypt messages in RSA. It uses Discord messages (or any message within 2000 characters, really) to generate RSA keys.

## How does this work?
The RSA algorithm takes two prime numbers as input and generates keys from there. 

My program takes in a string of text, converts the string to ASCII values, and computes both the sum of these array values and the sum of one less than the full array. It then finds the next highest prime number from both of these values, and generates keys with these two values.

## Why does this exist?
I learn best through doing. I wanted to learn more about cryptography and the C programming language. Hence, I created this.

## Compiling with `gcc`:
`gcc -o discord-rsa main.c rsa.c ascii.c`
