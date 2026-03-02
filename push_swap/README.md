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


## Additional Options


# Resources

# Overview of Deliverable
## The Rules

## The Algorithm

## Modified Functions

### libft
These functions are found in the `ps_libft_mod` directory.

Function Name | Modified from | Modification(s) Made
-|-|-
ft_arrlen | ft_strlen | Takes in a `char**` string array instead of a `char*` string.<br/>If I'm stupid, I'm changing this to be a `int**` array instead.
ft_atoi_e | ft_atoi | Takes in an extra `error` variable to be set to `2` if the function fails to properly convert via `ft_atoi`.
ft_strjoin_free | ft_strjoin | Frees the `char *s1` passed into the function after joining `s1` and `s2`.<br/>`s2` is a stack variable, so it does not have to be freed.`
ft_split_two | ft_split | Takes in an extra `char c2` (so basically both ' ' and '\n') and does the normal `ft_split` according to both chars.


### ft_printf
<table></table>
