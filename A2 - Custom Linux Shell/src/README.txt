I have done this assignment on "macOS Mojave Version 10.14.6"

INTRODUCTION
We use Terminal/Command Prompt but we have never thought of how it works.
By this assignment I learnt how the shell actually works, I have made my own customised shell, having my own commands.

I have 2 programs in C.
     ->Makefile
     ->2018CS10330.c     i.e. the shell code.
     ->run.c             i.e. the helper code to run the shell

//Makefile
Makefile compiles the helper file(i.e. run.c) and the shell file(i.e. shell.c) and creates their executable. It then finally runs the executable( i.e.RUN) of the helper programs.

//run.c
It uses fork command to create a child process and run the SHELL in the process. It makes the parent waits until the SHELL finishes its task.

//shell.c
I have taken input using scanf and the made a 2d array to store the input command as tokens. I have not use strtok command.
It compares the first command with "cd","mkdir","rmdir","pwd","exit"; and then executes the tasks using conditional statement.
open is used to link file for reading and writing input and output.
dup2(fd, 0) => It reads input and stores in memory using file descriptor.
dup2(fd, 1) => It write output and stores in memory using file descriptor.
wait(NULL) => It pauses the parent process until the child process gets completed
