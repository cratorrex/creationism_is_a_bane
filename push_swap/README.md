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
export ARGS="$(shuf -i 1-1000 -n100 | tr "\n" " ")"
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

### RADIX
> Radish ipsum dolor sit amet

Radix is a sort that utilises bitshifting to accomplish. Because of this, the complexity of the sort is approximately `1.51 * n (log n)` (rounded to 2 decimal places)



## Modified Functions

### libft
These functions are found in the `ps_libft_mod` directory.

Function Name | Modified from | Modification(s) Made
-|-|-
ft_arrlen | ft_strlen | Takes in a `char**` string array instead of a `char*` string.<br/>If I'm stupid, I'm changing this to be a `int**` array instead.
ft_atoi_e | ft_atoi | Takes in an extra `error` variable to be set to `2` if the function fails to properly convert via `ft_atoi`.
ft_strjoin_free | ft_strjoin | Frees the `char *s1` passed into the function after joining `s1` and `s2`.<br/>`s2` is a stack variable, so it does not have to be freed.
ft_split_two | ft_split | Takes in an extra `char c2` (so basically both ' ' and '\n') and does the normal `ft_split` according to both chars.
