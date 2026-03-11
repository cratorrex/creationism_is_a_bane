*This project has been created as part of the 42 curriculum by thtay*.

# Description
### push_swap - Because Swap_push doesn’t feel as natural
push_swap is a project that aims to recreate sorting algorithms but with a twist.  
There are two stacks, `a` and `b`. You're given a set of input integers in stack `a`, such that the starting input of `1, 3, 7, 4, 2` results in the following structure:
```
Initial Arrangement:               Resulting in the arrangement:
-------------                      -------------
|  a  |  b  |   The goal is to     |  a  |  b  |
-------------   use the rules      -------------
|  1  |     |   given to sort      |  1  |     |
|  3  |     |   the stack `a`      |  2  |     |
|  7  |     |   into an            |  3  |     |
|  4  |     |   ascending order.   |  4  |     |
|  2  |     |                      |  7  |     |
-------------                      -------------
```
Below is an example of sorting the given integers with the alloted rules.  
**There's probably a better way to do this, and this is what this project aims to do.**  
[See below for a detailed explanation of the rules.](#The-Rules)  
```
-------       -------      -------       -------      ------- ...
 a | b   rra   a | b   sa   a | b   rra   a | b   pb   a | b  ...
-------  >>>  -------  >>  -------  >>>  -------  >>  ------- ...
 1 |           2 |          1 |           4 |          1 | 4  ...
 3 |           1 |          2 |           1 |          2 |    ...
 7 |           3 |          3 |           2 |          3 |    ...
 4 |           7 |          7 |           3 |          7 |    ...
 2 |           4 |          4 |           7 |         ------- ...
-------       -------      -------       -------              ...

...      -------      -------      -------      -------     
... rra   a | b   pa   a | b   ra   a | b   ra   a | b      
... >>>  -------  >>  -------  >>  -------  >>  -------     S
...       7 | 4        4 |          7 |          1 |        O
...       1 |          7 |          1 |          2 |        L
...       2 |          1 |          2 |          3 |        V
...       3 |          2 |          3 |          4 |        E
...      -------       3 |          4 |          7 |        D
...                   -------      -------      -------     
```
The stack was solved with the order below, in which the program we create has to print out, line by line. This will be checked against a given checker program.
```
rra     
sa      
rra     
pb      
rra     
pa      
```

# Instructions
Running the `make` command in this directory will compile the `libft` and `ft_printf` libraries into a `libft.a` before compiling the rest of the program with this compiled binary, into a `push_swap` program.

For evaluation purposes, the `checker_linux` binary will not be included (get your own copy :3)

## Additional Options
The Makefile also has been equipped with a few debug options from the program itself.

Adding `MOVES=1` will print a display of the stacks as they are in the code, where the first number is the argument passed, and the second number is the order (in expected ascending).

Adding `ERRORS=1` will print alongside any errors found, an error code (custom codes) and the associated error in parsing the argument(s).


## Execution
The program can be run with a simple command:
```bash
#Examples
./push_swap 3 2 1
./push_swap 9 1 4 6 3 2 100
./push_swap "123321 4453423      " 123
```

To generate a random set of numbers into an environment variable, use the following command.
```bash
export ARGS="$(shuf -i 1-1000 -n100 | tr "\n" " ")";
```
Afterwhich the program can be run with
```bash
./push_swap $ARGS
```
<sub>The `tr` command is used specifically because the `checker_linux` binary does not accept `"\n"` newlines...</sub>

# Resources
Perplexity AI

[Sound of Sorting](https://panthema.net/2013/sound-of-sorting/) <-- this was what got me into sorting algorithms, as an enjoyer, but not an analyst...

push_swap Visualizers 

# Overview of Deliverable
## The Rules
There are a total of 11 rules the program can use, categorized into 4 types.

#### PUSH (PA / PB)
Moves the first item of the other stack onto the target stack.
> `PA` moves the first item from Stack B to the top of Stack A and vice versa.

#### SWAP (SA / SB // SS)
Swaps the first two items of the target stack
> Stack A has `2, 1, 5, 7`.  
> `SA` will swap the positions of 2 and 1, resulting in:
> 
> `1, 2, 5, 7`.

> `SS` does both `SA` and `SB` at the same time, while only costing one move.

#### ROTATE (RA / RB // RR)
Rotates the target stack in such a way the first item is now the last item.
> `[1], 4, 5, 3` > Rotates into > `4, 5, 3, 1`.

> `RR` does both `RA` and `RB` at the same time, while only costing one move.

#### REVERSE-ROTATE (RRA / RRB // RRR)

Rotates the target stack in such a way the last item is now the first item.
> `1, 4, 5, [3]` > Rotates into > `3, 1, 4, 5`.

> `RRR` does both `RRA` and `RRB` at the same time, while only costing one move.

## The Algorithm

Radix was the chosen algorithm, and as such the program also ranks the initial arguments accordingly.  
`1, 4, 17, 6` would be ranked as `1, 2, 4, 3`.

### 2 <= x <= 5 (Early Sorting)
Brute forced in a way, following a set pattern.

> 2 case: If it's not sorted, do the `SA` action.

> 3 case: Move the 3rd rank out of the top 2 positions if found (by either `RA` or `RRA`), then do the 2 case.

> 4 case: `PB` the 4th rank to `Stack B`, do the 3 case, `PA` the 4th rank back to `Stack A`, and finally `RA` until the 1st rank is on top.

> 5 case: `PB` the 4th and 5th ranks to `Stack B`, do the 3 case in `Stack A`, and the 2 case in `Stack B`. `PA` the rest back to `Stack A` and `RA` until the 1st rank is on top.  
<sub>(this method takes up to 12 steps on worst case, and 6 on best case)</sub>

### LSD RADIX (Least Significant Digit)
> Radish ipsum dolor sit amet

Radix is a sort that utilises bitshifting to accomplish. The way it works is that given a certain bit, either most or least, it will sort all integers (items) based on if it's bit is on or off. `ON` goes to the top section, and `OFF` goes to the bottom section. This continues for each subsequent bit until it reaches the other end of bits that the integers come in.

Let's take for example the sequence `1, 9, 5, 4, 3`, ranked as `1 5 4 3 2`, which we will use throughout this example.
Since we're working with the least significant digit (LSD) variation of Radix, we'll start off by comparing the 1s bit, or basically `is this number ODD?`

The way that radix works in `push_swap`, is that we only need to use 3 `RULES`: `PA`, `RA`, `PB`.
```c
We replicate radix by going through stack A once through with "RA", and when we encounter a number with the 1s bit "OFF", we "PB" them instead.
Once we finish this run, we "PA" back the numbers we pushed to stack B.

//End of the first run
stack A: [ 1 5 3 ] || stack B: [ 2 4 ]
//This is 5 moves, as we went through the entire stack.

//We then spend the next two moves to push 2 and 4 back to stack A
stack A: [ 4 2 1 5 3 ]
```
The next pass is to check if the 2s bit is on. This is where we need to introduce the concept of bitwise operators.  
We have the integer `n` which we first declared as value `1`. We will bitshift this number once (or otherwise multiply this number by 2)
```c
n = n << 1; // n is now value 2 (bitshifted once.)

If we instead did "n = n << 2;", we would be bitshifting twice, such that "n = 4", instead of 2 or 3.
```
The way we compare if the 2s bit is on, we use this `if` statement.
```c
if (stack item & n)
Not "% n = 0", as that will constitute all even numbers instead.
```
So we carry on with the comparison, resulting in:
```c
stack A: [ 2 3 ] || stack B: [ 5 1 4 ]
//Pushing back to get
stack A: [ 4 1 5 2 3 ]

Another 5 moves and another 3 moves to push back, resulting in a running total of 15 moves.
```
Bitshift it once more, and we get:
```c
stack A: [ 4 5 ] || stack B: [ 3 2 1 ]
//Pushing back to get
stack A: [ 1 2 3 4 5 ]

Final Moves: 23
```
You can see from this example why Radix would not be a good choice for lower numbers, but for higher numbers, the efficiency goes logarithmically higher.

The complexity of the sort is `n (log n)` normally, and approximately `1.5 * n * ceil(log2 n)` (rounded to 1 decimal place) for `push_swap`, considering the algorithm.  
1.5 is the approximate multiplier to complete one runthrough, the 0.5x on top is due to the amount of times we need to push back the numbers from stack B due to it's binural nature.  
And we see a jump in moves whenever we add a new bit into the mix, which is at every power of 2. This jump becomes less pronounced as we move up in numbers, due to it being linear.

## Modified Functions

### libft
These functions are found in the `ps_libft_mod` directory.

Function Name | Modified from | Modification(s) Made
-|-|-
ft_arrlen | ft_strlen | Takes in a `char**` string array instead of a `char*` string.<br/>If I'm stupid, I'm changing this to be a `int**` array instead.
ft_atoi_e | ft_atoi | Takes in an extra `error` variable to be set to `2` if the function fails to properly convert via `ft_atoi`.
ft_strjoin_free | ft_strjoin | Frees the `char *s1` passed into the function after joining `s1` and `s2`.<br/>`s2` is a stack variable, so it does not have to be freed.
ft_split_two | ft_split | Takes in an extra `char c2` (so basically both ' ' and '\n') and does the normal `ft_split` according to both chars.
