#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 on success, 1 for invalid usage, and 2 for exit command.
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		interactive_shell();
	}
	else if (argc == 2)
	{
		non_interactive_shell(argv[1]);
	}
	else
	{
		my_fprintf(stderr, "Usage: %s [command]\n", argv[0]);
		return (1);
	}

	return (0);
}

/**
 * process_input - Process user input and execute commands
 * @args: An array of command arguments
 * @line: The input line from the user
 * @status: The status code for the shell
 */
void process_input(char **args, char *line, int *status)
{
	char *start = line;

	while (*start == ' ')
		start++;
	char *end = line + _strlen(line) - 1;

	while (end > start && *end == ' ')
		end--;
	*(end + 1) = '\0';

	if (_strlen(start) > 0)
	{
		char *token = strtok(start, " ");
		int argIndex = 0;

		while (token != NULL && argIndex < MAX_NUM_ARGS)
		{
			args[argIndex++] = token;
			token = strtok(NULL, " ");
		}
		args[argIndex] = NULL;

		if (_strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(*status);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			print_environment();
		}
		else
		{
			*status = execute_command(args, 0);
		}
	}
	free(line);
}

/**
 * interactive_shell - Run the interactive shell
 */
void interactive_shell(void)
{
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, ":) ", 3);

		char *line = NULL;
		size_t size = 0;
		int numRead;

		numRead = getline(&line, &size, stdin);
		if (numRead >= 0)
		{
			line[numRead - 1] = '\0';
			char *args[MAX_NUM_ARGS + 1];

			process_input(args, line, &status);
		}
		else
		{
			free(line);
			break;
		}
	}
}

/**
 * non_interactive_shell - Run the non-interactive
 * shell with a specified command
 * @command: The command to execute
 */
void non_interactive_shell(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(2);
	}
	else
	{
		char *args[MAX_NUM_ARGS + 1];
		char *token = strtok(command, " ");
		int argIndex = 0;

		while (token != NULL && argIndex < MAX_NUM_ARGS)
		{
			args[argIndex++] = token;
			token = strtok(NULL, " ");
		}
		args[argIndex] = NULL;
		int status = execute_command(args, 0);

		if (status != 0)
		{
			my_fprintf(stderr, "Command exited with status %d\n", status);
		}
	}
}
