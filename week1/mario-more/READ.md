# Problem to Solve: mario-more

Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

![pyramids](https://cs50.harvard.edu/x/2024/psets/1/mario/more/pyramids.png)

In a file called `mario.c` in a folder called `mario-more`, implement a program in C that recreates that pyramid, using hashes (`#`) for bricks, as in the below:

```markdown
   #  #
  ##  ##
 ###  ###
####  ####
```

And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

## How to Test Your Code

Does your code work as prescribed when you input

- `-1` (or other negative numbers)?
- `0`?
- `1` through `8`?
- `9` or other positive numbers?
- letters or words?
- no input at all, when you only hit Enter?