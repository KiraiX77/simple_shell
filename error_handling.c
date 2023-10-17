#include "shell.h"

void print_command_not_found(int count, const char *command_name)
{   print_error_message(count, command_name, "not found"); }

void print_no_permission(int count, const char *command_name)
{   print_error_message(count, command_name, "permission denied"); }

void print_error_message(int count, const char
*command_name, const char *message)
{
	char *shell_name = _strdup(SHELL_NAME);

	if (shell_name == NULL)
	{	perror("strdup");
		exit(EXIT_FAILURE);
	}

	my_fprintf(stderr, ".%s: %d: %s: %s\n", shell_name,
	count, command_name, message);
	free(shell_name);
}
