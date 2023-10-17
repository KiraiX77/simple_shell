#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable or NULL if not found
 */
char *my_getenv(const char *name)
{
	/* "environ" declared manually */
	/* extern char **environ; */

	if (name == NULL)
	{
		return (NULL);
	}

	size_t name_len = _strlen(name);

	for (char **env = environ; *env != NULL; env++)
	{
		if (starts_with_variable_name(*env, name, name_len))
		{
			return (*env + name_len + 1);
		}
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
	for (char **env = environ; *env != NULL; env++)
	{
		my_fprintf(stdout, "%s\n", *env);
	}
}
