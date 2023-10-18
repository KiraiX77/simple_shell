#include "shell.h"

/**
 * change_directory - Change the current directory of the process
 * @path: The directory to change to (or NULL for the home directory)
 *
 * Return: 0 on success, -1 on failure
 */
int change_directory(const char *path)
{
	char new_directory[MAX_PATH_LENGTH];
	const char *home = my_getenv("HOME");
	const char *oldpwd = my_getenv("OLDPWD");

	if (path == NULL)
	{
		if (home == NULL)
		{	my_fprintf(stderr, "cd: HOME not set\n");
			return (-1); }
		path = home;
	}
	else if (_strcmp(path, "-") == 0)
	{
		if (oldpwd == NULL)
		{
			my_fprintf(stderr, "cd: OLDPWD not set\n");
			return (-1); }
		path = oldpwd;
	}

	if (getcwd(new_directory, MAX_PATH_LENGTH) == NULL)
	{	perror("getcwd");
		return (-1); }

	if (chdir(path) == -1)
	{	perror("chdir");
		return (-1); }

	if (set_env_variable("OLDPWD", new_directory) == -1)
	{	return (-1); }

	if (getcwd(new_directory, MAX_PATH_LENGTH) == NULL)
	{	perror("getcwd");
		return (-1); }

	if (set_env_variable("PWD", new_directory) == -1)
	{	return (-1); }

	return (0);
}

/**
 * cd_command - Handle the cd command
 * @args: An array of command arguments
 *
 * Return: 0 on success, 1 on failure
 */
int cd_command(char **args)
{
	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{	return (change_directory(NULL)); }
	else if (_strcmp(args[1], "-") == 0)
	{	return (change_directory(NULL)); }
	else
	{	return change_directory(args[1]); }
}

/**
 * execute_setenv_command - Execute the setenv command
 * @args: An array of command arguments
 *
 * Return: 0 on success, 1 on failure
 */
int execute_setenv_command(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (set_env_variable(args[1], args[2]) == -1)
		{	return (1); }
	}
	else
	{	my_fprintf(stderr, "setenv: Missing arguments\n");
		return (1);	}
	return (0);
}

/**
 * execute_unsetenv_command - Execute the unsetenv command
 * @args: An array of command arguments
 *
 * Return: 0 on success, 1 on failure
 */
int execute_unsetenv_command(char **args)
{
	if (args[1] != NULL)
	{
		if (unset_env_variable(args[1]) == -1)
		{	return (1); }
	}
	else
	{	my_fprintf(stderr, "unsetenv: Missing argument\n");
		return (1); }
	return (0);
}

/**
 * execute_cd_command - Execute the cd command
 * @args: An array of command arguments
 *
 * Return: 0 on success, 1 on failure
 */
int execute_cd_command(char **args)
{
	(void)args;
	return (0);
}
