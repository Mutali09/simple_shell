#include "shell.h"
/**
* _atoi - function for converting a str to int
* @s: String for conversion
* Return: int converted
*/
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int found_digit = 0;

	while (*s)
	{
		if (*s == '-' || *s == '+')
		{
			if (*s == '-')
				sign *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			found_digit = 1;
		}
		else if (found_digit)
		{
			break;
		}
		s++;
	}
	return (result * sign);
}
/**
 * str_cmp - function to compare two strings
 * @str1: the first string
 * @str2: the second string
 * @n: the number of characters to compare
 *
 * Return: 0 if the strings are equal
*/
int str_cmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}

	for (i = 0; i < n; ++i)
	{
		if (str1[i] != str2[i] || *str1 == '\0' || *str2 == '\0')
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return (0);
}
/**
 * *_strcat - function to concatenate two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the destination string
*/
char *_strcat(char *dest, const char *src)
{
	int index_dest = 0;
	int index_src = 0;

	while (dest[index_dest] != '\0')
	{
		index_dest++;
	}
	while (src[index_src] != '\0')
	{
		dest[index_dest] = src[index_src];
		index_dest++;
		index_src++;
	}
	dest[index_dest] = '\0';
	return (dest);
}
/**
 * str_cpy - function to copy a string
 * @dest: the destination string
 * @src: the source string
 * @n: limiter for the number of characters to copy
 *
 * Return: a pointer to the copied string
*/
char *str_cpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/**
* _isdigit - function checks for a digit 0 to 9
* @c: digit to the checked
* Return: 1 if digit 0 Otherwise
*/
int _isdigit(int c)
{
	if (c >=  '0' && c <= '9')
		return (1);
	else
		return (0);
}

