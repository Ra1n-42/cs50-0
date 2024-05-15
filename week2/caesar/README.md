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
some plaintext (i.e., an unencrypted message), `pi` is the \( \text{i}^{th} \)
