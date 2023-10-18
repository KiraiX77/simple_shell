#include "shell.h"

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated string, or NULL on failure
 */
char *_strdup(const char *str)
{
	size_t len;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	dup = malloc(len);

	if (dup == NULL)
		return (NULL);

	_strncpy(dup, str, len);
	return (dup);
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strncmp - Compare two strings up to n characters
 * @s1: The first string
 * @s2: The second string
 * @n: The number of characters to compare
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	while (n > 0 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{	i++;
		n--; }
	if (n == 0)
		return (0);
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

/**
 * _strncpy - Copy a string up to n characters
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of characters to copy
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 * _strncat - Concatenate two strings with a limit
 * on the number of characters to append
 * @dest: The destination string
 * @src: The source string
 * @dest_size: The maximum size of the destination buffer
 */
void _strncat(char *dest, const char *src, size_t dest_size)
{
	size_t dest_len = _strlen(dest);
	size_t src_len = _strlen(src);
	size_t i;

	for (i = 0; i < src_len && i < (dest_size - dest_len - 1); i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
}
