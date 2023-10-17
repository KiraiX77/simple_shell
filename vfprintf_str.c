#include "shell.h"

/**
 * my_vfprintf_char - Write a character to the stream
 * @stream: The output stream
 * @ch: The character to write
 *
 * Return: The number of characters written, or -1 on error.
 */
int my_vfprintf_char(FILE *stream, char ch)
{
	if (write(fileno(stream), &ch, 1) == -1)
	{	return (-1); }
	return (1);
}

/**
 * my_vfprintf_int - Write an integer to the stream
 * @stream: The output stream
 * @num: The integer to write
 *
 * Return: The number of characters written, or -1 on error.
 */
int my_vfprintf_int(FILE *stream, int num)
{
	char num_str[12];
	int num_len = snprintf(num_str, sizeof(num_str), "%d", num);

	if (num_len < 0)
	{	return (-1); }
	if (write(fileno(stream), num_str, (size_t)num_len) == -1)
	{	return (-1); }
	return (num_len);
}

/**
 * my_vfprintf_str - Write a string to the stream
 * @stream: The output stream
 * @str: The string to write
 *
 * Return: The number of characters written, or -1 on error.
 */
int my_vfprintf_str(FILE *stream, const char *str)
{
	if (write(fileno(stream), str, _strlen(str)) == -1)
	{	return (-1); }
	return (_strlen(str));
}
