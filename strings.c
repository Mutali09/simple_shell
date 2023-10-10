#include "shell.h"
/**
 * _strchr - function to locate the first occurence of a character in a string
 * @s: the string to locate
 * @c: the character to locate
 *
 * Return: a pointer of the first occurence
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: 0 if the strings are equal
 *
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	return (*str1 - *str2);
}
/**
* _strcpy - function that copies the string pointed by src
* @dest: destination for the string
* @src: the string to be copied
* Return: String
*/
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}
/**
 * _strdup - function that returns a pointer to a newly allocated space in the
 * memory. It should contain a copy of the string given as parameter
 * @str: string to be passed
 * Return: Null if the string the null also NULL if there is insufficient
 * memory
 */
char *_strdup(const char *str)
{
	int i;
	char *arr;
	int size;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str);

	arr = malloc(sizeof(char) * (size + 1));

	if (arr != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			arr[i] = str[i];
		}
		arr[i] = '\0';
		return (arr);
	}
	else
	{
		return (NULL);
	}
}
/**
* _strlen - returns the length of a string
* @s: string to be counted
* Return: Awalys 0
*/
int _strlen(const char *s)
{
	int count;

	count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
