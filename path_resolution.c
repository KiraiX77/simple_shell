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
