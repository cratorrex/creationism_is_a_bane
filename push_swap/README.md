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
<table></table>

### ft_printf
<table></table>
