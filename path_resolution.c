𝓚𝓲𝓻𝓪𝓲
kirai_seijuro
SXFLoidLove_MaomaoNeko’s

𝓚𝓲𝓻𝓪𝓲 — 10/11/2023 12:07 PM
months :peepoDeadShrug:
./Cosfal — 10/11/2023 12:08 PM
Yeah ghur khluha elah w safi
𝓚𝓲𝓻𝓪𝓲 — 10/11/2023 12:08 PM
alx to us
./Cosfal — 10/11/2023 12:08 PM
hhhhhh all the time
𝓚𝓲𝓻𝓪𝓲 — 10/11/2023 12:09 PM
yllh f9ti ?
./Cosfal — 10/11/2023 12:10 PM
no it was a little bit before
but ylh glsst l ard
𝓚𝓲𝓻𝓪𝓲 — 10/11/2023 12:10 PM
whats the plan lyum
./Cosfal — 10/11/2023 12:11 PM
ill be working on those errors asat wakha mabghawesh
do you want me to send ya the code or till you finish with the exercises ?
𝓚𝓲𝓻𝓪𝓲 — 10/11/2023 12:12 PM
yes whenever u can so i can go over it w understand it
manb9ash khdam f labstract
./Cosfal — 10/11/2023 12:12 PM
i commented it as much as possible
./Cosfal — 10/11/2023 12:12 PM
bssh
./Cosfal — 10/11/2023 12:20 PM
#include "shell.h"

extern char **environ;

int execute_command(char **args, int command_count)
{
Expand
execute_command.c
4 KB
#include "shell.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        // Interactive mode
Expand
main.c
3 KB
#include "shell.h"

/**
 * construct_exec_path - Constructs the full path to an executable command.
 * @exec_path: A character array where the constructed full path will be stored.
 * @exec_path_size: The size of the exec_path buffer.
Expand
construct_exec_path.c
1 KB
#include "shell.h"

/**
 * print_command_not_found - Prints an error message for command not found
 * @count: The command count number
 * @command_name: The name of the command
Expand
error_messages.c
2 KB
#include <unistd.h>

/**
 * _putchar - writes the character c to stderr
 * @c: The character to print
 *
Expand
putchar.c
1 KB
#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
Expand
shell.h
1 KB
#include "shell.h"

/**
 * my_getenv - Gets the value of an environment variable
 * @name: The name of the environment variable
 *
Expand
my_getenv.c
1 KB
#include "shell.h"
/**
 * _strlen - returns length of string
 * @s: string
 * Return: lenght
 */
Expand
strlen.c
1 KB
#include "shell.h"

/**
 * _strncmp - Function that compares n characters of two strings.
 * @s1: type str compared
 * @s2: type str compared
Expand
strncmp.c
1 KB
#include "shell.h"

/**
 * _strncpy - a function that copy a n char
 * @dest: pointer of a char
 * @src: pointer of a char
Expand
strncpy.c
1 KB
#include "shell.h"

/**
 * _strdup - a function that duplicate a string
 * @str: string to copy
 * Description: allocate memory for an array
Expand
strdup.c
1 KB
𝓚𝓲𝓻𝓪𝓲 — 10/14/2023 6:08 PM
Hey man
./Cosfal — 10/14/2023 9:00 PM
hello bud
how are ya doing
𝓚𝓲𝓻𝓪𝓲 — 10/14/2023 9:04 PM
Cava cava
U ?
./Cosfal — 10/14/2023 9:05 PM
me too
fen chadha ?
𝓚𝓲𝓻𝓪𝓲 — 10/14/2023 9:11 PM
Ha7na yallah rj3t mn jam3
Just wanted to apologise :AFcatthumbsup:
Had project i spent most of my time gha trying to understand w study while you did the work and all i did was study what u did
Ive been pretty useless f had shell
But im sure ill make it up to u f future projects inshallah darori🫡
./Cosfal — 10/14/2023 9:19 PM
its totally okay bro, if ya understand and got those concepts its a win for us
𝓚𝓲𝓻𝓪𝓲 — 10/14/2023 9:19 PM
./Cosfal — 10/14/2023 9:20 PM
We are a team at the end Jalal
you have nothing to thank me for
yak ghur nta bikhir w malin dar cava endhum ?
𝓚𝓲𝓻𝓪𝓲 — 10/14/2023 9:21 PM
Sii a thank you is due when its due
𝓚𝓲𝓻𝓪𝓲 — 10/14/2023 9:21 PM
All good , ill get on discord in a bit
./Cosfal — 10/14/2023 9:23 PM
take your time bud
𝓚𝓲𝓻𝓪𝓲 — Yesterday at 10:35 PM
hello hello
./Cosfal — Yesterday at 11:04 PM
Hey bud
𝓚𝓲𝓻𝓪𝓲 — Yesterday at 11:04 PM
how have u been
./Cosfal — Yesterday at 11:06 PM
good and just with the code hhh
what about ya ?
𝓚𝓲𝓻𝓪𝓲 — Yesterday at 11:06 PM
./Cosfal — Yesterday at 11:07 PM
hhhh hanta fen chadha db
𝓚𝓲𝓻𝓪𝓲 — Yesterday at 11:08 PM
if u can talk doz ana f discord
./Cosfal — Yesterday at 11:09 PM
give me a 15 min
𝓚𝓲𝓻𝓪𝓲 — Yesterday at 11:09 PM
ofc
text me mli tji ill be afk
./Cosfal — Yesterday at 11:32 PM
m back
./Cosfal — Yesterday at 11:50 PM
#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
Expand
environment.c
2 KB
./Cosfal — Yesterday at 11:57 PM
#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
Expand
main.c
3 KB
./Cosfal — Today at 12:02 AM
#include "shell.h"

/**
 * construct_exec_path - Construct the full path to the executable
 * @exec_path: The buffer to store the constructed path
 * @exec_path_size: The size of the exec_path buffer
Expand
path_resolution.c
2 KB
﻿
./Cosfal
.cosfal
#include "shell.h"

/**
 * construct_exec_path - Construct the full path to the executable
 * @exec_path: The buffer to store the constructed path
 * @exec_path_size: The size of the exec_path buffer
 * @path_token: The token from the PATH environment variable
 * @command: The name of the command
 *
 * This function constructs the full path to the executable by combining the
 * path_token, a '/', and the command name. If the combined length exceeds the
 * buffer size, it exits with failure status.
 */
void construct_exec_path(char *exec_path, size_t exec_path_size,
const char *path_token, const char *command)
{
	if (token_and_command_length_exceeds_buffer_size(path_token,
	command, exec_path_size))
	{
		exit(EXIT_FAILURE);
	}

	_strncpy(exec_path, path_token, exec_path_size);
	_strncat(exec_path, "/", exec_path_size);
	_strncat(exec_path, command, exec_path_size);
}

/**
 * token_and_command_length_exceeds_buffer_size - Check if the
 * combined length of token and command exceeds the buffer size
 * @path_token: The token from the PATH environment variable
 * @command: The name of the command
 * @buffer_size: The size of the buffer
 *
 * Return: 1 if the combined length exceeds or equals buffer_size, 0 otherwise.
 */
int token_and_command_length_exceeds_buffer_size(const char *path_token,
const char *command, size_t buffer_size)
{
	size_t token_length = _strlen(path_token);
	size_t command_length = _strlen(command);

	return (token_length + 1 + command_length >= buffer_size);
}
