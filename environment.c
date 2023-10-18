#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable or NULL if not found
 */
char *my_getenv(const char *name)
{
	size_t name_len;
	char **env;

	if (name == NULL)
	{
		return (NULL);
	}

	name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (starts_with_variable_name(*env, name, name_len))
		{
			return (*env + name_len + 1); }
	}

	return (NULL);
}

/**
 * starts_with_variable_name - Check if an
 * environment variable starts with a given name
 * @env: The environment variable string
 * @name: The name to check
 * @name_len: The length of the name
 *
 * Return: 1 if the environment variable starts with the name, 0 otherwise
 */
int starts_with_variable_name(const char *env,
const char *name, size_t name_len)
{
	return (_strncmp(env, name, name_len) == 0 && env[name_len] == '=');
}

/**
 * print_environment - Print the current environment variables to stdout
 */
void print_environment(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		my_fprintf(stdout, "%s\n", *env);
	}
}

/**
 * set_env_variable - Set or modify an environment variable
 * @name: The name of the environment variable
 * @value: The value to set or modify
 *
 * Return: 0 on success, -1 on failure
 */
int set_env_variable(const char *name, const char *value)
{
	if (name == NULL)
	{	my_fprintf(stderr, "setenv: Missing variable name\n");
		return (-1);
	}

	if (setenv(name, value, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unset_env_variable - Unset an environment variable
 * @name: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env_variable(const char *name)
{
	if (name == NULL)
	{	my_fprintf(stderr, "unsetenv: Missing variable name\n");
		return (-1);
	}

	if (unsetenv(name) == -1)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
