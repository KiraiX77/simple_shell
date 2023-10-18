#include "shell.h"

/**
 * execute_command - Execute a command with arguments
 * @args: An array of command arguments
 * @command_count: The command count
 *
 * Return: The exit status of the command
 */
int execute_command(char **args, int command_count)
{
	char *path_copy;
	char *path;
	int status;

	if (args[0][0] == '/')
	{	return (execute_external_command(args, command_count)); }

	if (_strcmp(args[0], "setenv") == 0)
	{	return (execute_setenv_command(args)); }
	else if (_strcmp(args[0], "unsetenv") == 0)
	{	return (execute_unsetenv_command(args)); }
	else if (_strcmp(args[0], "cd") == 0)
	{	return (execute_cd_command(args)); }

	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == 0)
		{	return (execute_external_command(args, command_count)); }
		else
		{	return (handle_permission_error(command_count, args[0])); }
	}

	path = my_getenv("PATH");
	path_copy = _strdup(path);

	if (path_copy == NULL)
	{	perror("strdup");
		exit(EXIT_FAILURE); }

	status = search_and_execute_in_path(args, path_copy, command_count);

	free(path_copy);
	return (status);
}


/**
 * execute_external_command - Execute an external command
 * @args: An array of command arguments
 * @command_count: The command count
 *
 * Return: The exit status of the command
 */
int execute_external_command(char **args, int command_count)
{
	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == 0)
		{
			pid_t pid, status;

			pid = fork();
			if (pid == 0)
			{	execve(args[0], args, environ);
				my_fprintf(stderr, ".%s: %d: %s: not found\n",
				SHELL_NAME, command_count, args[0]);
				exit(127); }
			else if (pid > 0)
			{
				wait(&status);

				if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
				{
					my_fprintf(stderr, ".%s: %d: %s: not found\n",
					SHELL_NAME, command_count, args[0]); }
				command_count++;
				return (WEXITSTATUS(status)); }
		}
		else
		{
			print_no_permission(command_count, args[0]);
			return (126); }
	}
	else
	{	my_fprintf(stderr, ".%s: %d: %s: not found\n",
		SHELL_NAME, command_count, args[0]);
		return (127); }
	return (0);
}

/**
 * search_and_execute_in_path - Search for a command in the PATH and execute it
 * @args: An array of command arguments
 * @path_copy: A copy of the PATH environment variable
 * @command_count: The command count
 *
 * Return: The exit status of the command
 */
int search_and_execute_in_path(char **args, char *path_copy, int command_count)
{
	char *path_token = strtok(path_copy, ":");
	char exec_path[256];

	while (path_token != NULL)
	{
		construct_exec_path(exec_path, sizeof(exec_path), path_token, args[0]);
		if (access(exec_path, F_OK) == 0)
		{
			if (access(exec_path, X_OK) == 0)
			{
				pid_t pid, status;

				pid = fork();
				if (pid == 0)
				{	execve(exec_path, args, environ);
					print_no_permission(command_count, args[0]);
					exit(EXIT_FAILURE); }
				else if (pid > 0)
				{	wait(&status);

					if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
					{	print_command_not_found(command_count, args[0]); }
					command_count++;
					return (WEXITSTATUS(status)); }
			}
			else
			{	print_no_permission(command_count, args[0]);
				return (126); }
		}
		path_token = strtok(NULL, ":");
	}

	if (path_token == NULL)
	{	print_command_not_found(command_count, args[0]);
		return (0); }
	return (0); }
