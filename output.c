#include "shell.h"

/**
 * _putchar - Write a character to the standard output
 * @c: The character to write
 *
 * Return: On success, the number of characters written is returned.
 * On error, -1 is returned.
 */
int _putchar(char c)
{	return (write(STDOUT_FILENO, &c, 1)); }

/**
 * _strcmp - Compare two strings up to null-terminator or inequality
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if strings are equal, a positive/negative value if different.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{	return (*s1 - *s2); }
		s1++;
		s2++;
	}
	return (*s1 - *s2); }

/**
 * my_vfprintf - Write formatted output to the stream using a va_list
 * @stream: The output stream
 * @format: The format string
 * @args: The va_list of arguments
 *
 * Return: The number of characters written, or -1 on error.
 */
int my_vfprintf(FILE *stream, const char *format, va_list args)
{
	int chars_written = 0;

	while (*format != '\0')
	{
		if (*format != '%')
		{	chars_written += my_vfprintf_char(stream, *format); }
		else
		{	format++;
			if (*format == '\0')
			{	break; }

			switch (*format)
			{	case 'd':
				{	int num = va_arg(args, int);
					int num_written = my_vfprintf_int(stream, num);

					if (num_written == -1)
					{	return (-1); }
					chars_written += num_written;
					break; }
				case 's':
				{	const char *str = va_arg(args, const char *);
					int str_written = my_vfprintf_str(stream, str);

					if (str_written == -1)
					{	return (-1); }
					chars_written += str_written;
					break;
				}
				default:
				{	chars_written += my_vfprintf_char(stream, *format); }
			}
		}
		format++;
	}

	return (chars_written);
}


/**
 * my_fprintf - Write formatted output to the stream
 * @stream: The output stream
 * @format: The format string
 * @...: The variable number of arguments
 *
 * Return: The number of characters written, or -1 on error.
 */
int my_fprintf(FILE *stream, const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = my_vfprintf(stream, format, args);

	va_end(args);
	return (result);
}
