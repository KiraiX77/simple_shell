# Simple Shell Project

This is a simple shell project written in C. It provides a basic command-line interface for executing commands and managing environment variables. The shell supports several built-in commands and can execute external commands from the system's PATH.

## General

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Features

- Execute external commands.
- Implement built-in commands:
  - `cd`: Change the current working directory.
  - `setenv`: Set or modify environment variables.
  - `unsetenv`: Remove environment variables.
- Print error messages for command not found and permission denied.
- Display the current environment variables using the `env` command.
...

## Prerequisites

- GCC (GNU Compiler Collection) or another C compiler.
- A Unix-like operating system.

## Usage

1. Clone the repository to your local machine.
2. Compile the code using your C compiler:

   ```bash
   gcc -o simple_shell *.c
   ```

3. Run the shell:

   ```bash
   ./simple_shell
   ```

4. Use the shell to execute commands, e.g., `ls`, `echo`, built-in commands, etc.

## Built-in Commands

- `cd [directory]`: Change the current working directory.
- `setenv VARIABLE VALUE`: Set or modify an environment variable.
- `unsetenv VARIABLE`: Remove an environment variable.
- `env`: Display the current environment variables...

## Authors

ANAS FALAKI < anas.001falaki@gmail.com > Cohort 18
JALAL EDDINE HAFDI < kiraix77@gmail.com > Cohort 18

## Acknowledgments

- Inspired by the simplicity of Unix-like shells.
- The project made us love c and that counts for the ALX programme.
- The shell is an incredibly cool project.
