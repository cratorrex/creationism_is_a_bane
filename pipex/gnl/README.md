*This project has been created as part of the 42 curriculum by thtay*.

## DESCRIPTION
### Get Next Line - Reading a line from a file descriptor is way too tedious.
The goal of this project is to create a program that returns, `line-by-line`, the contents of a given file-descriptor `(fd)`, where the `fds` would consist purely of text files `(.txt)`. If multiple lines are read at once, they would need to be returned one by one.

#### Constraints and Considerations:
- We are only allowed to submit `3` files and an additional 3 for the Bonus, which was attempted. (inclusive of the header `.h` file respectively, totalling `6` submitted files.)
  - This basically allows us up to `10` functions total per part.
- The subject specifies that we cannot import our `libft` project in, but technically allows us to select a few functions to import that would be helpful in this project.
  - Those functions that were included are namely:
	- `ft_strdup`
	- `ft_memchr` (reworked slightly to check both the `\n` delimiter and NULLs)
	- `ft_strjoin` (reworked slightly to join the specific buffer length to the string, and freeing the first string after, as it has been replaced.)
	- `ft_strlen`
- For the bonus, the challenge is to both handle multiple `fds` at once while using only one `static` variable.
  - Many people have advised that this bonus is rather easy, and it kinda was!
- When exiting there is a need to free whatever memory was yet to be used, otherwise we risk it leaking. So there has to be a lot of consideration where we exit any functions to add a `free` statement. As tedious as it sounds, it is needed so as to optimise our code and curb the risk.

### Sequence of Execution (Algorithm Explanation)
#### get_next_line()
The base `get_next_line()` function is where all the needed variables are initialized, such as the `buffer` and `static stash` variables. If either of these could not be allocated, the program ends here. Otherwise, the code will go into the `gnl_read_loop()` function.
#### gnl_read_loop()
Here we first check if the given `fd` can be `read()` from, hence valid. Thereafter, it will continuously `read` from the `fd` until we encounter the `\n` delimiter, or the end of file (when `read()` returns `0`). The resulting joined `stash` is returned.
#### gnl_get_return() & gnl_trim_stash()
From the first appearance of the `\n` delimiter, we use `gnl_get_return()` to collect a string from the stash for the program to return, and afterwards pass it to `gnl_trim_stash()` to trim out the string up to the new line, and free it. If there is nothing left in `stash`, then it is also freed there before the `get_next_line()` function returns the collected string.

### LEARNING POINTS
> An understanding of what `ifndef` meant as "`if` `n`ot `def`ined", then `define` the macro here. This is also known as an [`#include guard`](https://en.wikipedia.org/wiki/Include_guard).

> A growing trouble I had when working on this was assuming GNL itself was going to attempt to read the whole file while returning lines, which was already denied in the subject pdf... the main is what would be receiving the next lines everytime and then re-calling GNL for the next line til EOF...

> Stack Overflow... I was supposed to malloc a buffer size, rather than define a macro-static array.
> - This is allowed, but will overflow the stack around the 2 MiB+ (2,000,000) allocation.


## INSTRUCTIONS
Since there is no Makefile allowed in this submission, compile the files with an appropriate main function (or the tests file at the root).  
If compiling files in this directory, insert the following command(s) into the terminal. Replace the first argument with the main file of choice.
```sh
cc YOUR_MAIN_FILE get_next_line.h get_next_line.c get_next_line_utils.c
```
The dependency files have already been checked with the `-Wall -Werror -Wextra` flags, so no problem will arise if a valid main file is compiled with the above command and the Warning flags.

Additionally, there is a `BUFFER_SIZE` macro that is allotted in the header file. The default value is `16`, but can be altered by adding the following to the compiler command., where `n` is the (positive integer) buffer size you want to define. 
```sh
-D BUFFER_SIZE=n
```
Be careful when trying to define a very high buffer size, as the program will take longer to execute.

<sub>The bonus is already implemented in the base submission and is just included for submission purposes... but either way, just append <code>_bonus</code> before the <code>.c</code> to each of the dependant files if you wanna... I guess...?</sub>

Finally, run the output file with
```
./a.out
```

## RESOURCES

- the `manual` page for `read(2)`, and `open(2)`
- Perplexity AI
- [Static Variable - Wikipedia](https://en.wikipedia.org/wiki/Static_variable)
- Stack Overflow (and also Stack Overflow)

### USAGE OF AI

A general pivot of model usage from GPT to Perplexity, where understanding of specific code use cases (in a general context) were sought out.

> The overview section is now on top, in the [#Description](#DESCRIPTION) section...