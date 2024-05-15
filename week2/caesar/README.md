# Problem to Solve: Caesar

![cipher](https://cs50.harvard.edu/x/2024/psets/2/caesar/cipher.jpg)

Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP instead. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.

The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

To be clear, then, here’s how encrypting `HELLO` with a key of 
 yields `IFMMP`:

```markdown
| Plaintext | Key 
| --------- | 
| H         | 1   
| E         | 1   
| L         | 1   
| L         | 1   
| O         | 1   
```
```markdown
| Plaintext | = ciphertext 
| --------- | 
| H         | 'I'
| E         | 'F'
| L         | 'M'
| L         | 'M'
| O         | 'P'
```
More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by `k` positions. More formally, if `p` is
some plaintext (i.e., an unencrypted message), `pi` is the i<sup>th</sup> character in `p`, and `k` is a secret key (i.e., a non-negative integer), then each letter, `ci`, in the ciphertext, `c` , is computed as

```markdown
$$
c_i = (p_i + k) \% 26
$$
```
wherein 
 here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as 
`0`, B (or b) as `1`, …, H (or h) as `7`, I (or i) as `8`, …, and Z (or z) as `25`. Suppose that Caesar just wants to say `Hi` to someone confidentially using, this time, a key, `k`, of 3. And so his plaintext, `p`, is Hi, in which case his plaintext’s first character, `p0`, is H (aka 7), and his plaintext’s second character, `p1`, is i (aka 8). His ciphertext’s first character, `c0`, is thus K, and his ciphertext’s second character, `c1`, is thus `L`. Make sense?

In a file called `caesar.c` in a folder called `caesar`, write a program that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.

## Specification
Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.

- Implement your program in a file called `caesar.c` in a directory called `caesar`.
- Your program must accept a single command-line argument, a non-negative integer. Let’s call it `k` for the sake of discussion.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` (which tends to signify an error) immediately.
- If any of the characters of the command-line argument is not a decimal digit, your program should print the message `Usage: ./caesar key` and return from `main` a value of `1`.
- o not assume that `k`  will be less than or equal to 26. Your program should work for all non-negative integral values of `k` less than `2`<sub>`31`</sub>-`26`. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for 
 that’s too big or almost too big to fit in an `int`. (Recall that an `int` can overflow.) But, even if `k` is greater than `26` , alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if `k` is `27`