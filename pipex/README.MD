*This project has been created as part of the 42 curriculum by thtay*.

# Description
### Pipex - <button alt="subject did not provide a tagline.">🚧⚠🚧</button> [Pipes.](https://www.youtube.com/watch?v=iDLmYZ5HqgM) | | | | | | | |

A way to funnel from one point to another... I think...  
Why does that happen when they are vertically upright? Well simple, these aren't ordinary metal pipes!

#### This project focuses on handling pipes.
Pipes in general programming terminology are a way of pumping the output of a certain command as an input to another.

Example: `ls -l | grep 'd'`  
Consider the command `ls -l`. It lists down all the files of the current directory in detail. Now let's pipe it into another command `grep 'd'`. This gets all the lines of the output and only shows those that contain at least the character `d`.  
This is good if you can get a hands on feel for how this works, but basically, this acts as a way to chain together many commands to simplify and fine-tune the output into one that is desirable.

Let's go it a step further with:  
`< loremipsum.txt grep 'od' | sed "s/o/I/g" > edit.txt`

Given a Lorem Ipsum text file, we want to collect all lines that contain the string `o`, replacing a global occurrence of `o` with `I`, finally outputting the result to an `edit.txt`.

# Instructions
**RUN THE EXECUTABLE ON A REGULAR TERMINAL, OTHERWISE THERE WILL BE FD LEAKS**

# Resources
man pages for each of the tools used  
[valgrind documentation](https://www.man7.org/linux/man-pages/man1/valgrind.1.html) (for `--track-fds=all`)  
Perplexity AI

# Overview of Deliverable
## The Mechanics
#### Process IDs (pid)
`fork` gives us a new processID `pid_t` to work with, which contains an exact copy of the current process.

`execve` executes a binary.

#### File Descriptors (fd)
`pipe` creates two fds for our program to read[0] from and write[1] to. The write-head must be closed before the read-head can be used.

`dup` (and `dup2`) attempts to open a new `fd` and transfer the given fd's progress to that `fd`, closing fd(s) where necessary.
> This is used a lot, in conjunction with the `pipe` heads.  
> We'll use the words `transfer`, and `connect` to represent this function, and it's subsequent interactions with our `pipefds`, respectively, later on when explaining the code, so bear this in mind.

`access` determines if we can access a file at the given location.

## Order of operations
Let's take the example from before: `< loremipsum.txt grep 'o' | sed "s/o/I/g" > edit.txt` and break it down in depth.

We first use the input `<` redirection from reading `loremipsum.txt` and send it to the `grep 'o'` command.  
> `grep 'o'` uses `loremipsum.txt` as the input.

The output from the `grep` command is then piped into the `sed` command which through a `regex` expression, replaces the **g**lobal occurrence of `o` with `I`.

Finally, the output of this command is redirected `>` into `edit.txt`.
> Remember this is just a write redirection, and not the `>>` APPEND redirection. So whatever used to be in the `edit.txt` file will be `overwritten`.  

We end up with this pipeline.
```
 -------------------------------------------------------
(loremipsum.txt) > grep 'o' >> sed "s/o/I/g" > (edit.txt)
 -------------------------------------------------------

//or simply
 ---------------------------------
(file1) 0 cmd1 1 | 0 cmd2 1 (file2)
 ---------------------------------
```

### The Translation
Let's first assume we do not need to worry about opening files or pipes.

We first fork the process and accomplish the below.  
Transfer the opened source fd to the `stdin` stream, then connect the `stdout` stream to the write end of our first pipe.
```c
dup2(infile, 0);
dup2(pipe1[1], 1);
```
